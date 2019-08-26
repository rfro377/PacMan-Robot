
/* ========================================
 * Laboratory Exercise 4
 *
 * Program a UART to receive the string from a RF receiver.
 * The RF receiver : 57.6k b/s, 8b, no parity, no flow control, one start and one stop bit
 *
 * Copyright Univ of Auckland, 2016
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF Univ of Auckland.
 *
 * ========================================
*/
#include <project.h>
#include <stdio.h>

//* ========================================
#define TOGGLE_LED LED_Write(~LED_Read())
#define PACKETSIZE 32
#define RXSTRINGSIZE 255

#define FALSE 0
#define TRUE 1

#define BUF_SIZE 64 // USBUART fixed buffer size

#define CHAR_NULL '0'
#define CHAR_BACKSP 0x08
#define CHAR_DEL 0x7F
#define CHAR_ENTER 0x0D
#define LOW_DIGIT '0'
#define HIGH_DIGIT '9'

#define SOP 0xaa
//* ========================================
uint8 flag_rx = 0;
uint8 flag_packet = 0;
uint8 flag_KB_string = 0;
//* ========================================
char rf_string[RXSTRINGSIZE];
char displaystring[BUF_SIZE] = "UART Lab Exercise 4\n";
char line[BUF_SIZE], entry[BUF_SIZE];
uint8 usbBuffer[BUF_SIZE];
//* ========================================
typedef struct data_main {
	int8            rssi;	
    uint8           index;			// index number of packet. incremented number
	uint16			robot_xpos;	 	// 
	uint16			robot_ypos;		//
    uint16         robot_orientation;
	uint16			g0_xpos;		//
	uint16			g0_ypos;		//
	uint16			g0_speed;		//
	uint16		g0_direction;	//
	uint16			g1_xpos;		//
	uint16			g1_ypos;		//
	uint16			g1_speed;		//
    uint16		g1_direction;	//
    uint16			g2_xpos;		//
    uint16			g2_ypos;		//
    uint16			g2_speed;		//
    uint16		g2_direction;	//
} vtype1;

struct data_main system_state;
//* ========================================



//* ========================================
void usbPutString(char *s);
void usbPutChar(char c);
void handle_rx_binary();
void handle_rx_ascii();
void handle_usb();
//* ========================================
int main()
{
    
    CyGlobalIntEnable; /* Enable global interrupts. */
 
    USBUART_Start(0,USBUART_5V_OPERATION);
   
    
    usbPutString(displaystring);
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        /* Place your application code here. */
        handle_usb();
        
        if (flag_KB_string == 1)
        {
            usbPutString("you entered: ");
            usbPutString(line);
            usbPutChar('\n');
//            sprintf(displaystring,"you entered: %s\n",line);
//            usbPutString(displaystring);
            flag_KB_string = 0;   
        }
               
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
//* ========================================
void usbPutChar(char c)
{
    while (USBUART_CDCIsReady() == 0);
    USBUART_PutChar(c);
}
//* ========================================
void handle_rx_binary()
{
  
}
//* ========================================
void handle_rx_ascii()
{
 
}

//* ========================================
void handle_usb()
{
    
    // handles input at terminal, echos it back to the terminal
    // turn echo OFF, key emulation: only CR
    // entered string is made available in 'line' and 'flag_KB_string' is set
    
    static uint8 usbStarted = FALSE;
    static uint16 usbBufCount = 0;
    uint8 c; 
    

    if (!usbStarted)
    {
        if (USBUART_GetConfiguration())
        {
            USBUART_CDC_Init();
            usbStarted = TRUE;
        }
    }
    else
    {
        if (USBUART_DataIsReady() != 0)
        {  
            c = USBUART_GetChar();
            if ((c == 13) || (c == 10))
            {
                entry[usbBufCount]= '\0';
                strcpy(line,entry);
                usbBufCount = 0;
                flag_KB_string = 1;
            }
            else 
            {
                if (((c == CHAR_BACKSP) || (c == CHAR_DEL) ) && (usbBufCount > 0) )
                    usbBufCount--;
                else
                {
                    if (usbBufCount > (BUF_SIZE-1) )
                    {
                       USBUART_PutChar('!');        
                    }
                    else
                        entry[usbBufCount++] = c;  
                }
            }
        }
    }     
}
/* [] END OF FILE */
