/*******************************************************************************
* File Name: Sensor5.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Sensor5_H) /* Pins Sensor5_H */
#define CY_PINS_Sensor5_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Sensor5_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Sensor5__PORT == 15 && ((Sensor5__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Sensor5_Write(uint8 value);
void    Sensor5_SetDriveMode(uint8 mode);
uint8   Sensor5_ReadDataReg(void);
uint8   Sensor5_Read(void);
void    Sensor5_SetInterruptMode(uint16 position, uint16 mode);
uint8   Sensor5_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Sensor5_SetDriveMode() function.
     *  @{
     */
        #define Sensor5_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Sensor5_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Sensor5_DM_RES_UP          PIN_DM_RES_UP
        #define Sensor5_DM_RES_DWN         PIN_DM_RES_DWN
        #define Sensor5_DM_OD_LO           PIN_DM_OD_LO
        #define Sensor5_DM_OD_HI           PIN_DM_OD_HI
        #define Sensor5_DM_STRONG          PIN_DM_STRONG
        #define Sensor5_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Sensor5_MASK               Sensor5__MASK
#define Sensor5_SHIFT              Sensor5__SHIFT
#define Sensor5_WIDTH              1u

/* Interrupt constants */
#if defined(Sensor5__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Sensor5_SetInterruptMode() function.
     *  @{
     */
        #define Sensor5_INTR_NONE      (uint16)(0x0000u)
        #define Sensor5_INTR_RISING    (uint16)(0x0001u)
        #define Sensor5_INTR_FALLING   (uint16)(0x0002u)
        #define Sensor5_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Sensor5_INTR_MASK      (0x01u) 
#endif /* (Sensor5__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Sensor5_PS                     (* (reg8 *) Sensor5__PS)
/* Data Register */
#define Sensor5_DR                     (* (reg8 *) Sensor5__DR)
/* Port Number */
#define Sensor5_PRT_NUM                (* (reg8 *) Sensor5__PRT) 
/* Connect to Analog Globals */                                                  
#define Sensor5_AG                     (* (reg8 *) Sensor5__AG)                       
/* Analog MUX bux enable */
#define Sensor5_AMUX                   (* (reg8 *) Sensor5__AMUX) 
/* Bidirectional Enable */                                                        
#define Sensor5_BIE                    (* (reg8 *) Sensor5__BIE)
/* Bit-mask for Aliased Register Access */
#define Sensor5_BIT_MASK               (* (reg8 *) Sensor5__BIT_MASK)
/* Bypass Enable */
#define Sensor5_BYP                    (* (reg8 *) Sensor5__BYP)
/* Port wide control signals */                                                   
#define Sensor5_CTL                    (* (reg8 *) Sensor5__CTL)
/* Drive Modes */
#define Sensor5_DM0                    (* (reg8 *) Sensor5__DM0) 
#define Sensor5_DM1                    (* (reg8 *) Sensor5__DM1)
#define Sensor5_DM2                    (* (reg8 *) Sensor5__DM2) 
/* Input Buffer Disable Override */
#define Sensor5_INP_DIS                (* (reg8 *) Sensor5__INP_DIS)
/* LCD Common or Segment Drive */
#define Sensor5_LCD_COM_SEG            (* (reg8 *) Sensor5__LCD_COM_SEG)
/* Enable Segment LCD */
#define Sensor5_LCD_EN                 (* (reg8 *) Sensor5__LCD_EN)
/* Slew Rate Control */
#define Sensor5_SLW                    (* (reg8 *) Sensor5__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Sensor5_PRTDSI__CAPS_SEL       (* (reg8 *) Sensor5__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Sensor5_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Sensor5__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Sensor5_PRTDSI__OE_SEL0        (* (reg8 *) Sensor5__PRTDSI__OE_SEL0) 
#define Sensor5_PRTDSI__OE_SEL1        (* (reg8 *) Sensor5__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Sensor5_PRTDSI__OUT_SEL0       (* (reg8 *) Sensor5__PRTDSI__OUT_SEL0) 
#define Sensor5_PRTDSI__OUT_SEL1       (* (reg8 *) Sensor5__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Sensor5_PRTDSI__SYNC_OUT       (* (reg8 *) Sensor5__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Sensor5__SIO_CFG)
    #define Sensor5_SIO_HYST_EN        (* (reg8 *) Sensor5__SIO_HYST_EN)
    #define Sensor5_SIO_REG_HIFREQ     (* (reg8 *) Sensor5__SIO_REG_HIFREQ)
    #define Sensor5_SIO_CFG            (* (reg8 *) Sensor5__SIO_CFG)
    #define Sensor5_SIO_DIFF           (* (reg8 *) Sensor5__SIO_DIFF)
#endif /* (Sensor5__SIO_CFG) */

/* Interrupt Registers */
#if defined(Sensor5__INTSTAT)
    #define Sensor5_INTSTAT            (* (reg8 *) Sensor5__INTSTAT)
    #define Sensor5_SNAP               (* (reg8 *) Sensor5__SNAP)
    
	#define Sensor5_0_INTTYPE_REG 		(* (reg8 *) Sensor5__0__INTTYPE)
#endif /* (Sensor5__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Sensor5_H */


/* [] END OF FILE */
