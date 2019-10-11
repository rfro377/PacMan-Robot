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
//#include <linkedlist.h>
#include <math.h>


/* Macros */

#define distance (279) //1 count = 0.358 cm
#define target_speed (15)
#define LOW (0)
#define HIGH (1)
#define OPT_ROTS (10)
#define turn360 (28800000) //90 counts // 34560000 108
#define turn1 (80000)
#define mode (3)           //MODE1 = Speed Line  //MODE 2 Curves/U BETTA  //MODE 3 Right turn //MODE 4 Speed No Line //MODE 5 RF //MODE 6 straight
#define int_speed1 (100)
#define int_speed2 (100)
#define int_speedmode1 (120)
#define int_speedmode2 (124)
#define RFdistance (100)
#define SOP 0xaa
/* 

OPT_ROTS equation

((1/(target frequency of ChaA)) x Num of rotations before adjustment) x (input clock 24mhz)
1/75 x 10 x 24000000
*/

/* IMPORTANT STATE LOGIC */

    enum turn {L, R, I}; // LEFT RIGHT IGNORE
    enum turn state;
    enum turn array[3];
    array[0] = L;
    array[1] = R;
    array[2] = I;
    state = I;
 
/* Global Varibles */
    int16 sensor1_mv;
    int16 sensor2_mv;
    int16 sensor3_mv;
    int16 sensor4_mv;
    int16 sensor5_mv;
    int16 sensor1;
    int16 sensor2;
    int16 sensor3;
    int16 sensor4;
    int16 sensor5;
    int16 batteryVoltage;
    int16 adccount;
    int16 mVolts;
    uint8 disablePWM = 0;
    uint8 pwm1_speed = int_speed1; //hard coded init speeds
    uint8 pwm2_speed = int_speed2; //hard coded init speeds
    uint16 pwm1_speed4 = 120; //hard coded init speeds
    uint16 pwm2_speed4 = 124; //hard coded init speeds
    uint8 int_ready = 0;
    int8 Count1 = 10;
    int8 Count2 = 10;
    int16 final_count = 0;
    uint8 led = 0;
    int16 reverse1 = 0;
    int16 reverse2 = 0;
    int16 first_data = 1;
    uint16 originx = 0;
    uint16 originy = 0;
    uint16 dx = 0;
    uint16 dy = 0;
    uint16 dist_travelledy;
    uint16 dist_travelledx;
    uint16 dist_travelled;
    double double_dist_travelled;
    int16 RF_stop = 0;
    int16 bytecount_val = 0;
    int16 valid_rf = 0;
    int16 flag_rx = 0;
    uint16 packet[2];
    uint16 robot_xpos_temp;
    uint16 robot_ypos_temp;
    uint16 robot_xpos = 9999;
    uint16 robot_ypos = 9999;
    uint16 last_diffx = 0;
    uint16 last_diffy = 0;
    uint16 leftTurn = 0;
    uint16 rightTurn = 0;
    
     
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
    uint8 rotateflag = 0;
    
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
        pwm1_speed4--;
         
    }
    else if(abs(Count1) < OPT_ROTS){
        pwm1_speed4++;
         
    }else{
        
    }
    
    if(Count2 == 0){
        
    }
    else if(abs(Count2) > OPT_ROTS){
        pwm2_speed4--;
    }
    else if(abs(Count2) < OPT_ROTS){
        pwm2_speed4++;
    }else{
        
    }
    PWM_1_WriteCompare1(0);
    PWM_1_WriteCompare2(pwm1_speed4);
    PWM_2_WriteCompare1(pwm2_speed4);
    PWM_2_WriteCompare2(0);
}

void stop(){
    PWM_1_WriteCompare1(0);
    PWM_1_WriteCompare2(0);
    PWM_2_WriteCompare1(0);
    PWM_2_WriteCompare2(0);
}

void rotate(uint32 angle){
    uint32 period = angle*turn1;
    Timer_2_WriteCounter(0);
    Timer_2_WritePeriod(period);
    Timer_2_WriteCounter(0);
    PWM_1_WriteCompare1(pwm1_speed);
    PWM_1_WriteCompare2(0);
    PWM_2_WriteCompare1(pwm2_speed);
    PWM_2_WriteCompare2(0);
    Timer_2_Enable();
}

void check_ADC(){
    sensor1_mv = ADC_SAR_1_GetResult16();
    sensor1_mv = ADC_SAR_1_CountsTo_mVolts(sensor1_mv);
    sensor2_mv = ADC_SAR_Seq_1_GetResult16(0);
    sensor2_mv = ADC_SAR_Seq_1_CountsTo_mVolts(sensor2_mv);
    sensor3_mv = ADC_SAR_Seq_1_GetResult16(1);
    sensor3_mv = ADC_SAR_Seq_1_CountsTo_mVolts(sensor3_mv);
    sensor4_mv = ADC_SAR_Seq_1_GetResult16(2);
    sensor4_mv = ADC_SAR_Seq_1_CountsTo_mVolts(sensor4_mv);
    sensor5_mv = ADC_SAR_Seq_1_GetResult16(3);
    sensor5_mv = ADC_SAR_Seq_1_CountsTo_mVolts(sensor5_mv);
    if(sensor1_mv > 2500){
        sensor1 = 1;
    }else{
        sensor1 = 0;
    }
    if(sensor2_mv > 2500){
        sensor2 = 1;
    }else{
        sensor2 = 0;
    }
    if(sensor3_mv > 2500){
        sensor3 = 1;
    }else{
        sensor3 = 0;
    }
    if(sensor4_mv > 2500){
        sensor4 = 1;
    }else{
        sensor4 = 0;
    }
    if(sensor5_mv > 2500){
        sensor5 = 1;
    }else{
        sensor5 = 0;
    }
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
    final_count = final_count + abs(Count1);
    uint8 count = Timer_1_ReadStatusRegister();
    Timer_1_STATUS;
    Timer_1_Init();
    Timer_1_Enable();
    Timer_1_Start();
}

CY_ISR(Timer_2_Int_Handler)
{
    LED_Write(HIGH);
   
    PWM_1_WriteCompare1(0);
    PWM_1_WriteCompare2(0);
    PWM_2_WriteCompare1(0);
    PWM_2_WriteCompare2(0);
    rotateflag = 1;
}

CY_ISR(USBUART_Int_Handler)
{
    //UART_dataReady = 1;
    char rx = UART_1_GetChar();
    if(rx == SOP){
        if(bytecount_val == 32){
            valid_rf = 1;   
        }
        bytecount_val = 0;
        flag_rx = 0;
    }else{
        packet[bytecount_val % 2] = rx;
        if(bytecount_val % 2 == 1){
            flag_rx = 1;
        }
        bytecount_val = (bytecount_val + 1);
    }
}

void rx_handler(){
   
    if(flag_rx == 1){
        isr_2_Stop();
        flag_rx = 0;
        uint16 packet_bytes =(packet[1] << 8 | (packet[0]));
    
        switch (bytecount_val){
            case 4:
                robot_xpos_temp = packet_bytes;
                break;
            
            case 6:
                robot_ypos_temp = packet_bytes;
                break;
            default:
                break;
        }
         isr_2_StartEx(USBUART_Int_Handler);
    }
    if(valid_rf == 1){
        robot_xpos = robot_xpos_temp;
        robot_ypos = robot_ypos_temp;
        valid_rf = 0;
    }
    
   
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
    if(mode != 5){
        Timer_1_Enable();
        Timer_1_Start();
    }
    Timer_2_Init();
    isr_1_StartEx(Timer_1_Int_Handler);
    isr_2_StartEx(USBUART_Int_Handler);
    isr_3_StartEx(Timer_2_Int_Handler);
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
    
    LED_Write(LOW);
    int i = 0;
    
    while(i != 1000000){
       i++;
    }
    
    PWM_1_WriteCompare1(0);
    PWM_1_WriteCompare2(pwm1_speed4);
    PWM_2_WriteCompare1(pwm2_speed4);
    PWM_2_WriteCompare2(0);
    
    
    int index = 0; 
    int movement;
    int flag = 0;
    i = 0;
    LED_Write(LOW);   
    
    
    //test stuff remove later maybe?
    int turnFlagL = 0;
    int turnFlagR = 0;
    int turnState = 0;
    int turnpart = 0;
    
    
    
    for(;;)
    {
        check_ADC();
        if(mode == 1){
            if(final_count < distance){
                if(sensor2 == 0){ 
                    pwm2_speed4 = int_speedmode2;
                    pwm1_speed4 = 0;
                }
                if(sensor3 == 0){ 
                    pwm1_speed4 = int_speedmode1;
                    pwm2_speed4 = 0;
                } 
                
                if (sensor2 == 0 && sensor3 == 0) {
                    if (pwm2_speed4 > pwm1_speed4) {
                        pwm1_speed4 = 0;
                        pwm2_speed4 = int_speedmode2;
                    } else if (pwm1_speed4 > pwm2_speed4) {
                        pwm2_speed4 = 0;
                        pwm1_speed4 = int_speedmode2;
                    } else {
                        pwm2_speed4 = int_speedmode2;
                        pwm1_speed4 = int_speedmode1;
                    }
                }
                if((sensor3 == 1) && (sensor2 == 1)){
                    pwm2_speed4 = int_speedmode2;
                    pwm1_speed4 = int_speedmode1;
                }

                PWM_1_WriteCompare1(0);
                PWM_1_WriteCompare2(pwm1_speed4);
                PWM_2_WriteCompare1(pwm2_speed4);
                PWM_2_WriteCompare2(0);  
            } else {
                PWM_1_WriteCompare1(0);
                PWM_1_WriteCompare2(0);
                PWM_2_WriteCompare1(0);
                PWM_2_WriteCompare2(0);
            }
        }
        
        if(mode == 2){
            if(sensor2 == 0){
                if (sensor1 == 1 && sensor3 == 1){
                    pwm2_speed = 140;
                    pwm1_speed = 140;
                    PWM_1_WriteCompare1(pwm1_speed);
                    PWM_1_WriteCompare2(0);
                    PWM_2_WriteCompare1(pwm2_speed);
                    PWM_2_WriteCompare2(0);
                } else {
                    pwm2_speed = 100;
                    pwm1_speed = 100;
                    PWM_1_WriteCompare1(0);
                    PWM_1_WriteCompare2(0);
                    PWM_2_WriteCompare1(pwm2_speed);
                    PWM_2_WriteCompare2(0);
                }
            }
            if(sensor3 == 0){
                if (sensor1 == 1 && sensor2 == 1){
                    pwm1_speed = 140;
                    pwm2_speed = 140;
                    PWM_1_WriteCompare1(0);
                    PWM_1_WriteCompare2(pwm1_speed);
                    PWM_2_WriteCompare1(0);
                    PWM_2_WriteCompare2(pwm2_speed); 
                } else {
                    pwm1_speed = 100;
                    pwm2_speed = 100;
                    PWM_1_WriteCompare1(0);
                    PWM_1_WriteCompare2(pwm1_speed);
                    PWM_2_WriteCompare1(0);
                    PWM_2_WriteCompare2(0); 
                }
            }
            
            if((sensor2 == 1 && sensor3) == 1 || (sensor2 == 0 && sensor3 == 0)){
                pwm1_speed = 100;
                pwm2_speed = 100;
                PWM_1_WriteCompare1(0);
                PWM_1_WriteCompare2(pwm1_speed);
                PWM_2_WriteCompare1(pwm2_speed);
                PWM_2_WriteCompare2(0); 
            }
        }
        
        if(mode == 3){
            
            if(turnState == 0){
                if(sensor2 == 0 && sensor3 == 1){
                    pwm2_speed = int_speed2;
                    pwm1_speed = int_speed1;
                    PWM_1_WriteCompare1(0);
                    PWM_1_WriteCompare2(0);
                    PWM_2_WriteCompare1(pwm2_speed);
                    PWM_2_WriteCompare2(0);
                    if(sensor4 == 0 && (leftTurn == 1)){
                        turnState = 1;
                        turnFlagL = 1;
                    }
                }
                if(sensor3 == 0 && sensor2 == 1){
                    pwm1_speed = int_speed1;
                    pwm2_speed = int_speed2;
                    PWM_1_WriteCompare1(0);
                    PWM_1_WriteCompare2(pwm1_speed);
                    PWM_2_WriteCompare1(0);
                    PWM_2_WriteCompare2(0); 
                    if(sensor5 == 0 && (rightTurn == 1)){
                        turnState = 1;
                        turnFlagR = 1;
                    }
                }
                
                if(sensor2 == 1 && sensor3 == 1){
                    pwm1_speed = 100;
                    pwm2_speed = 100;
                    PWM_1_WriteCompare1(0);
                    PWM_1_WriteCompare2(pwm1_speed);
                    PWM_2_WriteCompare1(pwm2_speed);
                    PWM_2_WriteCompare2(0); 
                }
            } else {
                if(turnFlagL == 1){
                    if(sensor3 == 0){
                        turnState = 0;
                        turnFlagL = 0;
                    } 
                }
                if(turnFlagR == 1){
                    if(sensor2 == 0){
                        turnState = 0;
                        turnFlagR = 0;
                    } 
                }
            }
        }  
        
        if(mode == 4){
            if(final_count < distance){
                if(int_ready == 1){
                    
                    int_ready = 0;
                    if(abs(Count1) > OPT_ROTS){
                        pwm1_speed4 --;
                        LED_Write(LOW);
                    }
                    if(abs(Count1) < OPT_ROTS){
                        pwm1_speed4 ++;
                        LED_Write(HIGH);
                    }
            
                    if(abs(Count2) > OPT_ROTS){
                        pwm2_speed4 --;
                    }
                    if(abs(Count2) < OPT_ROTS){
                        pwm2_speed4 ++;
                    }
                    
                    if (pwm1_speed4 > 255){
                        pwm1_speed4 = 255;
                    }
                    if (pwm2_speed4 > 255){
                        pwm2_speed4 = 255;
                    }
                    PWM_1_WriteCompare1(0);
                    PWM_1_WriteCompare2(pwm1_speed4);
                    PWM_2_WriteCompare1(pwm2_speed4);
                    PWM_2_WriteCompare2(0);
                }
            } else{
                
                PWM_1_WriteCompare1(0);
                PWM_1_WriteCompare2(0);
                PWM_2_WriteCompare1(0);
                PWM_2_WriteCompare2(0);
            }
        }
        
         if(mode == 5){
            if((dist_travelledx < RFdistance)&&(dist_travelledy < RFdistance)){
                rx_handler();
                if(robot_xpos != 9999){
                    if(first_data == 1){
                        originx = robot_xpos;
                        originy = robot_ypos;
                        dx = originx;
                        dy = originy;
                        last_diffx = 0;
                        last_diffy = 0;
                        first_data = 0;
                        Timer_1_Enable();
                        Timer_1_Start();
                    }else {
                        dx = robot_xpos;
                        dy = robot_ypos;
                    }
                    if((((abs(originx - dx))/4) < (last_diffx + 100)) && ((abs(originx - dx))/4) > ((last_diffx - 100))){
                        dist_travelledx = ((abs(originx - dx))/4);
                        last_diffx = dist_travelledx;
                    }
                    if((((abs(originy - dy))/4) < (last_diffy + 100)) && ((abs(originy - dy))/4) > ((last_diffy - 100))){
                        dist_travelledy = ((abs(originy - dy))/4);
                        last_diffy = dist_travelledy;
                    }
                }
                
                //moving forward logic
                
                if(first_data == 0){
                    
                    if(int_ready == 1){
                        int_ready = 0;
                        moveForward();
                    }
                }else{
                    LED_Write(HIGH);
                    stop();
                }
            }else{
                LED_Write(LOW);
                stop();
            }
        }
            
        if(mode == 6){
            //line tracking.
            if((sensor2 == 0 || (sensor4 == 0 && sensor5 == 1)) && sensor3 == 1){
                pwm2_speed = int_speed2;
                pwm1_speed = int_speed1;
                PWM_1_WriteCompare1(0);
                PWM_1_WriteCompare2(0);
                PWM_2_WriteCompare1(pwm2_speed);
                PWM_2_WriteCompare2(0);
            }
            if((sensor3 == 0 || (sensor5 == 0 && sensor4 == 1)) && sensor2 == 1){
                pwm1_speed = int_speed1;
                pwm2_speed = int_speed2;
                PWM_1_WriteCompare1(0);
                PWM_1_WriteCompare2(pwm1_speed);
                PWM_2_WriteCompare1(0);
                PWM_2_WriteCompare2(0); 
            }
            if(sensor2 == 1 && sensor3 == 1 && sensor4 == 1 && sensor5 == 1){
                pwm1_speed = int_speed1;
                pwm2_speed = int_speed2;
                PWM_1_WriteCompare1(0);
                PWM_1_WriteCompare2(pwm1_speed);
                PWM_2_WriteCompare1(pwm2_speed);
                PWM_2_WriteCompare2(0); 
            }
        }
        /*if(mode == 7){
            linkedlist ll;
            data d;
            setdata(&d,1,2,3,4,5,6,7); 
            createlinkedlist(&ll, d);
            addfirst(&ll, createdata(6,6,3,6,6,6,7));
            addlast(&ll, createdata(8,8,8,8,8,8,8));
            data data = getlast(&ll);
            data = getfirst(&ll);
        }
        */
            
        
        /*sensor1 = ADC_SAR_1_GetResult16();
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
        
        sensor1 = ADC_SAR_1_GetResult16();
        sensor1 = ADC_SAR_1_CountsTo_mVolts(sensor1); 
        if(sensor1 > 2500){
                LED_Write(HIGH);
        }else{
            PWM_1_WriteCompare1(0);
            PWM_1_WriteCompare2(0);
            PWM_2_WriteCompare1(0);
            PWM_2_WriteCompare2(0);
            disablePWM = 1;
            LED_Write(LOW);
        }
        */

        
    }
}

/* [] END OF FILE */
