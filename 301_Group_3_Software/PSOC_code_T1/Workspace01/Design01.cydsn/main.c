/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <project.h>
#include <stdio.h>


/* Macros */

#define LOW (0)
#define HIGH (1)
#define OPT_ROTS (10)
/* 

OPT_ROTS equation

((1/(target frequency of ChaA)) x Num of rotations before adjustment) x (input clock 24mhz)

1/55 x 10 x 24000000
*/

/* Global Varibles */
    int16 sensor1;
    int16 batteryVoltage;
    int16 adccount;
    int16 mVolts;
    uint8 disablePWM = 0;
    uint8 pwm1_speed = 89; //hard coded init speeds
    uint8 pwm2_speed = 93; //hard coded init speeds
    uint8 int_ready = 0;
    int8 Count1 = 10;
    int8 Count2 = 10;
    uint8 led = 0;
    
/* UART VARIBLES */
    
    char displaystring[64];
    uint8 UART_dataReady = 0;
    char rssi[4];
	char indexnumber[3];
    char xloc[4];
    char yloc[4];
    char angle10[3];
    uint8 UART_startString = 0;
    uint8 UART_comma = 0;
	uint8 UART_index = 0;
    
/* HELPER FUNCTIONS */
    
uint8 checkNumeric(char rx);
uint8 checkNegative(char rx);
uint8 checkComma(char rx);
uint8 checkLeftBracket(char rx);
uint8 checkRightBracket(char rx);
uint8 processChar(char, char* );
void appendChar(char* s, char rx, uint8 ind);

void moveForward(){
    if(Count1 == 0){
        
    }else if(abs(Count1) > OPT_ROTS){
        pwm1_speed--;
         
    }
    else if(abs(Count1) < OPT_ROTS){
        pwm1_speed++;
         
    }else{
        
    }
    
    if(Count2 == 0){
        
    }
    else if(abs(Count2) > OPT_ROTS){
        pwm2_speed--;
    }
    else if(abs(Count2) < OPT_ROTS){
        pwm2_speed++;
    }else{
        
    }
    PWM_1_WriteCompare1(pwm1_speed);
    PWM_1_WriteCompare2(pwm1_speed);
    PWM_2_WriteCompare1(pwm2_speed);
    PWM_2_WriteCompare2(pwm2_speed);
}

void usbPutString(char *s)
{
// !! Assumes that *s is a string with allocated space >=64 chars     
//  Since USB implementation retricts data packets to 64 chars, this function truncates the
//  length to 62 char (63rd char is a '!')
    
    while (USBUART_CDCIsReady() == 0);
    s[63]='\0';
    s[62]='!';
    USBUART_PutData((uint8*)s,strlen(s));
}

void usbPutChar(char c)
{
    while (USBUART_CDCIsReady() == 0);
    USBUART_PutChar(c);
}

uint8 dataParser(char rx){
	if (rx == '#'){
		UART_comma = 0;
		rssi[0] = '\0';
		indexnumber[0] = '\0';
		UART_index = 0;
		UART_startString = 1;
		return 0;
	}
	else if (UART_startString == 1){
		switch(UART_comma) {
			case 0: 
				if (UART_index == 0){
					if (checkNegative(rx) == 1){
						appendChar(rssi, rx, UART_index);
						UART_index++;
						return 0;
					}
					else{
						UART_startString = 0;
						return 0;
					}
				}
				if (checkNumeric(rx) == 1){
					appendChar(rssi, rx, UART_index);
					UART_index++;
					return 0;
				}
				if (checkComma(rx) == 1){
					if (UART_index == 1){
						UART_startString = 0;
						return 0;
					}
					UART_comma++;
					UART_index = 0;
					return 0;
				}
				UART_startString = 0;
				return 0;
			    break;
			case 1:
				if (processChar(rx, indexnumber) == 0){
					return 0;
				}
				UART_startString = 0;
				return 0;
			    break;
			case 2:
				if (checkLeftBracket(rx) == 1){
					UART_comma++;
					return 0;
				}
				else{
					UART_startString = 0;
					return 0;
				}
				break;
			case 3:
				if (processChar(rx, xloc) == 0){
					return 0;
				}
				UART_startString = 0;
				return 0;
				break;
			case 4:
				if (processChar(rx, yloc) == 0){
					return 0;
				}
				UART_startString = 0;
				return 0;
				break;
			case 5:
				if (processChar(rx, angle10) == 0){
					return 0;
				}
				if (checkRightBracket(rx) == 1){
					if (UART_index == 0){
						UART_startString = 0;
						return 0;
					}
					else{
						UART_startString = 0;
						return 1;
					}
				}
				UART_startString = 0;
				return 0;
				break;
	    }
	}
	return 0;
}

uint8 processChar(char rx, char* s){
	if (checkNumeric(rx) == 1){
		appendChar(s, rx, UART_index);
		UART_index++;
		return 0;
	}
	if (checkComma(rx) == 1){
		if (UART_index == 0){
			UART_startString = 0;
			return 0;
		}
		else{
			UART_comma++;
			UART_index = 0;
			return 0;
		}
	}
	return 1;
}

uint8 checkNumeric(char rx){
	if ((rx >= '0') && (rx <= '9')){
		return 1;
	}
	return 0;
}

uint8 checkNegative(char rx){
	if (rx == '-'){
		return 1;
	}
	return 0;
}

uint8 checkComma(char rx){
	if (rx == ','){
		return 1;
	}
	return 0;
}

uint8 checkLeftBracket(char rx){
	if (rx == '['){
		return 1;
	}
	return 0;
}

uint8 checkRightBracket(char rx){
	if (rx == ']'){
		return 1;
	}
	return 0;
}

void appendChar(char* s, char rx, uint8 ind) {
    s[ind] = rx;
    s[ind+1] = '\0';
    return;
}

CY_ISR(Timer_1_Int_Handler)
{
    int_ready = 1;
    Count1 = QuadDec_1_GetCounter();
    Count2 = QuadDec_2_GetCounter();
    QuadDec_1_SetCounter(0);
    QuadDec_2_SetCounter(0);
    uint8 count = Timer_1_ReadStatusRegister();
    Timer_1_STATUS;
     if(led == 1){
        led = 0;
    }else{
        led = 1;
    }
    if(led == 1){
        
    }else{
        
    }
    Timer_1_Init();
    Timer_1_Enable();
    Timer_1_Start();
}

CY_ISR(USBUART_Int_Handler)
{
    UART_dataReady = 1;
}
    
/* MAIN */

int main()
{
    /* Enable global interrupts. */
    CyGlobalIntEnable; 
    
    
    
    
    //Practical Test Modes
    
    //***************************************
    QuadDec_1_Start();
    QuadDec_2_Start();
    ADC_SAR_1_Enable();
    ADC_SAR_1_Start();
    ADC_SAR_1_IRQ_Enable();
    ADC_SAR_1_StartConvert();
    ADC_SAR_Seq_1_Start();
    ADC_SAR_Seq_1_IRQ_Enable();
    ADC_SAR_Seq_1_StartConvert();
    PWM_1_Start();
    PWM_2_Start();
    Timer_1_Enable();
    Timer_1_Start();
    isr_1_StartEx(Timer_1_Int_Handler);
    isr_2_StartEx(USBUART_Int_Handler);
    UART_1_Start();
    USBUART_Start(0,USBUART_5V_OPERATION);
    //PIN MAP//
    //ADC Sensor 1 1.5
    //ADC BatterVoltage 1.6
    //ADC Sensor 2 1.6
    //ADC Sensor 3 1.7
    //ADC Sensor 4 0.7
    //ADC Sensor 5 0.6
    //ADCREF 0.2
    //ADCREF 0.4
    //PWM1_1 3.0
    //PWM1_2 3.1
    //PWM2_1 2.5
    //Pwm2_2 2.6
    //chA1 0.1
    //chB1 0.0
    //chA2 1.4
    //chB2 1.2
    //***************************************
    
    
    // init pwm so hard coded speed
    PWM_1_WriteCompare1(pwm1_speed);
    PWM_1_WriteCompare2(pwm1_speed);
    PWM_2_WriteCompare1(pwm2_speed);
    PWM_2_WriteCompare2(pwm2_speed);
    LED_Write(LOW);
    int i = 0;
    while(i != 100000){
        i++;
    }
        
    for(;;)
    {
        
            
        sensor1 = ADC_SAR_1_GetResult16();
        sensor1 = ADC_SAR_1_CountsTo_mVolts(sensor1); 
        batteryVoltage = ADC_SAR_Seq_1_GetResult16(0);
        adccount = batteryVoltage;
        batteryVoltage = ADC_SAR_Seq_1_CountsTo_mVolts(batteryVoltage);
        batteryVoltage = batteryVoltage*2;
        if(batteryVoltage > 7500){
            LED_Write(HIGH);
            sprintf(displaystring,"Battery Voltage =  %dmv ADC Count = %d\r\n",batteryVoltage, adccount);
            usbPutString(displaystring);
        }else{
            LED_Write(LOW);
        }
        if(sensor1 > 2500 && disablePWM == 0){
            if(int_ready == 1){
               
                int_ready = 0;
                moveForward();
            }
        }else{
            PWM_1_WriteCompare1(0);
            PWM_1_WriteCompare2(0);
            PWM_2_WriteCompare1(0);
            PWM_2_WriteCompare2(0);
            disablePWM = 1;
            //LED_Write(HIGH);
        }
        if (UART_dataReady == 1)
        {
            char rx = UART_1_ReadRxData();
            if (dataParser(rx) == 1){
                sprintf(displaystring,"rssi=%s, index=%s, xpos=%s, ypos=%s, angle10=%s\r\n",rssi,indexnumber,xloc,yloc,angle10);
                usbPutString(displaystring);
            }
            UART_dataReady = 0;
        }
    }
}

/* [] END OF FILE */
