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
    int16 mVolts;
    uint8 dataReady = 0;
    uint8 disablePWM = 0;
    uint8 pwm1_speed = 89; //hard coded init speeds
    uint8 pwm2_speed = 93; //hard coded init speeds
    uint8 int_ready = 0;
    int8 Count1 = 10;
    int8 Count2 = 10;
    uint8 led = 0;

    
/* HELPER FUNCTIONS */
    
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
    UART_1_Start();
    UART_2_Start();
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
    
    for(;;)
    {
        sensor1 = ADC_SAR_1_GetResult16();
        sensor1 = ADC_SAR_1_CountsTo_mVolts(sensor1); 
        batteryVoltage = ADC_SAR_Seq_1_GetResult16(0);
        batteryVoltage = ADC_SAR_Seq_1_CountsTo_mVolts(batteryVoltage);
        batteryVoltage = batteryVoltage*2;
        if(batteryVoltage > 7500){
            LED_Write(HIGH);
        }else{
            LED_Write(LOW);
        }
        if(sensor1 > 2500){
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
        char rx = UART_1_GetChar();
        UART_2_PutChar(rx);    
    }
}

//UART_2_PutChar(char c)

/* [] END OF FILE */
