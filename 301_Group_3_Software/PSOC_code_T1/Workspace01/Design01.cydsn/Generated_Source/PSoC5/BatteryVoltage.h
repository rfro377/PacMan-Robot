/*******************************************************************************
* File Name: BatteryVoltage.h  
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

#if !defined(CY_PINS_BatteryVoltage_H) /* Pins BatteryVoltage_H */
#define CY_PINS_BatteryVoltage_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "BatteryVoltage_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 BatteryVoltage__PORT == 15 && ((BatteryVoltage__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    BatteryVoltage_Write(uint8 value);
void    BatteryVoltage_SetDriveMode(uint8 mode);
uint8   BatteryVoltage_ReadDataReg(void);
uint8   BatteryVoltage_Read(void);
void    BatteryVoltage_SetInterruptMode(uint16 position, uint16 mode);
uint8   BatteryVoltage_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the BatteryVoltage_SetDriveMode() function.
     *  @{
     */
        #define BatteryVoltage_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define BatteryVoltage_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define BatteryVoltage_DM_RES_UP          PIN_DM_RES_UP
        #define BatteryVoltage_DM_RES_DWN         PIN_DM_RES_DWN
        #define BatteryVoltage_DM_OD_LO           PIN_DM_OD_LO
        #define BatteryVoltage_DM_OD_HI           PIN_DM_OD_HI
        #define BatteryVoltage_DM_STRONG          PIN_DM_STRONG
        #define BatteryVoltage_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define BatteryVoltage_MASK               BatteryVoltage__MASK
#define BatteryVoltage_SHIFT              BatteryVoltage__SHIFT
#define BatteryVoltage_WIDTH              1u

/* Interrupt constants */
#if defined(BatteryVoltage__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in BatteryVoltage_SetInterruptMode() function.
     *  @{
     */
        #define BatteryVoltage_INTR_NONE      (uint16)(0x0000u)
        #define BatteryVoltage_INTR_RISING    (uint16)(0x0001u)
        #define BatteryVoltage_INTR_FALLING   (uint16)(0x0002u)
        #define BatteryVoltage_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define BatteryVoltage_INTR_MASK      (0x01u) 
#endif /* (BatteryVoltage__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define BatteryVoltage_PS                     (* (reg8 *) BatteryVoltage__PS)
/* Data Register */
#define BatteryVoltage_DR                     (* (reg8 *) BatteryVoltage__DR)
/* Port Number */
#define BatteryVoltage_PRT_NUM                (* (reg8 *) BatteryVoltage__PRT) 
/* Connect to Analog Globals */                                                  
#define BatteryVoltage_AG                     (* (reg8 *) BatteryVoltage__AG)                       
/* Analog MUX bux enable */
#define BatteryVoltage_AMUX                   (* (reg8 *) BatteryVoltage__AMUX) 
/* Bidirectional Enable */                                                        
#define BatteryVoltage_BIE                    (* (reg8 *) BatteryVoltage__BIE)
/* Bit-mask for Aliased Register Access */
#define BatteryVoltage_BIT_MASK               (* (reg8 *) BatteryVoltage__BIT_MASK)
/* Bypass Enable */
#define BatteryVoltage_BYP                    (* (reg8 *) BatteryVoltage__BYP)
/* Port wide control signals */                                                   
#define BatteryVoltage_CTL                    (* (reg8 *) BatteryVoltage__CTL)
/* Drive Modes */
#define BatteryVoltage_DM0                    (* (reg8 *) BatteryVoltage__DM0) 
#define BatteryVoltage_DM1                    (* (reg8 *) BatteryVoltage__DM1)
#define BatteryVoltage_DM2                    (* (reg8 *) BatteryVoltage__DM2) 
/* Input Buffer Disable Override */
#define BatteryVoltage_INP_DIS                (* (reg8 *) BatteryVoltage__INP_DIS)
/* LCD Common or Segment Drive */
#define BatteryVoltage_LCD_COM_SEG            (* (reg8 *) BatteryVoltage__LCD_COM_SEG)
/* Enable Segment LCD */
#define BatteryVoltage_LCD_EN                 (* (reg8 *) BatteryVoltage__LCD_EN)
/* Slew Rate Control */
#define BatteryVoltage_SLW                    (* (reg8 *) BatteryVoltage__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define BatteryVoltage_PRTDSI__CAPS_SEL       (* (reg8 *) BatteryVoltage__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define BatteryVoltage_PRTDSI__DBL_SYNC_IN    (* (reg8 *) BatteryVoltage__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define BatteryVoltage_PRTDSI__OE_SEL0        (* (reg8 *) BatteryVoltage__PRTDSI__OE_SEL0) 
#define BatteryVoltage_PRTDSI__OE_SEL1        (* (reg8 *) BatteryVoltage__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define BatteryVoltage_PRTDSI__OUT_SEL0       (* (reg8 *) BatteryVoltage__PRTDSI__OUT_SEL0) 
#define BatteryVoltage_PRTDSI__OUT_SEL1       (* (reg8 *) BatteryVoltage__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define BatteryVoltage_PRTDSI__SYNC_OUT       (* (reg8 *) BatteryVoltage__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(BatteryVoltage__SIO_CFG)
    #define BatteryVoltage_SIO_HYST_EN        (* (reg8 *) BatteryVoltage__SIO_HYST_EN)
    #define BatteryVoltage_SIO_REG_HIFREQ     (* (reg8 *) BatteryVoltage__SIO_REG_HIFREQ)
    #define BatteryVoltage_SIO_CFG            (* (reg8 *) BatteryVoltage__SIO_CFG)
    #define BatteryVoltage_SIO_DIFF           (* (reg8 *) BatteryVoltage__SIO_DIFF)
#endif /* (BatteryVoltage__SIO_CFG) */

/* Interrupt Registers */
#if defined(BatteryVoltage__INTSTAT)
    #define BatteryVoltage_INTSTAT            (* (reg8 *) BatteryVoltage__INTSTAT)
    #define BatteryVoltage_SNAP               (* (reg8 *) BatteryVoltage__SNAP)
    
	#define BatteryVoltage_0_INTTYPE_REG 		(* (reg8 *) BatteryVoltage__0__INTTYPE)
#endif /* (BatteryVoltage__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_BatteryVoltage_H */


/* [] END OF FILE */
