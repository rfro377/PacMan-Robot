/*******************************************************************************
* File Name: Sensor4.h  
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

#if !defined(CY_PINS_Sensor4_H) /* Pins Sensor4_H */
#define CY_PINS_Sensor4_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Sensor4_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Sensor4__PORT == 15 && ((Sensor4__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Sensor4_Write(uint8 value);
void    Sensor4_SetDriveMode(uint8 mode);
uint8   Sensor4_ReadDataReg(void);
uint8   Sensor4_Read(void);
void    Sensor4_SetInterruptMode(uint16 position, uint16 mode);
uint8   Sensor4_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Sensor4_SetDriveMode() function.
     *  @{
     */
        #define Sensor4_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Sensor4_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Sensor4_DM_RES_UP          PIN_DM_RES_UP
        #define Sensor4_DM_RES_DWN         PIN_DM_RES_DWN
        #define Sensor4_DM_OD_LO           PIN_DM_OD_LO
        #define Sensor4_DM_OD_HI           PIN_DM_OD_HI
        #define Sensor4_DM_STRONG          PIN_DM_STRONG
        #define Sensor4_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Sensor4_MASK               Sensor4__MASK
#define Sensor4_SHIFT              Sensor4__SHIFT
#define Sensor4_WIDTH              1u

/* Interrupt constants */
#if defined(Sensor4__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Sensor4_SetInterruptMode() function.
     *  @{
     */
        #define Sensor4_INTR_NONE      (uint16)(0x0000u)
        #define Sensor4_INTR_RISING    (uint16)(0x0001u)
        #define Sensor4_INTR_FALLING   (uint16)(0x0002u)
        #define Sensor4_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Sensor4_INTR_MASK      (0x01u) 
#endif /* (Sensor4__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Sensor4_PS                     (* (reg8 *) Sensor4__PS)
/* Data Register */
#define Sensor4_DR                     (* (reg8 *) Sensor4__DR)
/* Port Number */
#define Sensor4_PRT_NUM                (* (reg8 *) Sensor4__PRT) 
/* Connect to Analog Globals */                                                  
#define Sensor4_AG                     (* (reg8 *) Sensor4__AG)                       
/* Analog MUX bux enable */
#define Sensor4_AMUX                   (* (reg8 *) Sensor4__AMUX) 
/* Bidirectional Enable */                                                        
#define Sensor4_BIE                    (* (reg8 *) Sensor4__BIE)
/* Bit-mask for Aliased Register Access */
#define Sensor4_BIT_MASK               (* (reg8 *) Sensor4__BIT_MASK)
/* Bypass Enable */
#define Sensor4_BYP                    (* (reg8 *) Sensor4__BYP)
/* Port wide control signals */                                                   
#define Sensor4_CTL                    (* (reg8 *) Sensor4__CTL)
/* Drive Modes */
#define Sensor4_DM0                    (* (reg8 *) Sensor4__DM0) 
#define Sensor4_DM1                    (* (reg8 *) Sensor4__DM1)
#define Sensor4_DM2                    (* (reg8 *) Sensor4__DM2) 
/* Input Buffer Disable Override */
#define Sensor4_INP_DIS                (* (reg8 *) Sensor4__INP_DIS)
/* LCD Common or Segment Drive */
#define Sensor4_LCD_COM_SEG            (* (reg8 *) Sensor4__LCD_COM_SEG)
/* Enable Segment LCD */
#define Sensor4_LCD_EN                 (* (reg8 *) Sensor4__LCD_EN)
/* Slew Rate Control */
#define Sensor4_SLW                    (* (reg8 *) Sensor4__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Sensor4_PRTDSI__CAPS_SEL       (* (reg8 *) Sensor4__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Sensor4_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Sensor4__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Sensor4_PRTDSI__OE_SEL0        (* (reg8 *) Sensor4__PRTDSI__OE_SEL0) 
#define Sensor4_PRTDSI__OE_SEL1        (* (reg8 *) Sensor4__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Sensor4_PRTDSI__OUT_SEL0       (* (reg8 *) Sensor4__PRTDSI__OUT_SEL0) 
#define Sensor4_PRTDSI__OUT_SEL1       (* (reg8 *) Sensor4__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Sensor4_PRTDSI__SYNC_OUT       (* (reg8 *) Sensor4__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Sensor4__SIO_CFG)
    #define Sensor4_SIO_HYST_EN        (* (reg8 *) Sensor4__SIO_HYST_EN)
    #define Sensor4_SIO_REG_HIFREQ     (* (reg8 *) Sensor4__SIO_REG_HIFREQ)
    #define Sensor4_SIO_CFG            (* (reg8 *) Sensor4__SIO_CFG)
    #define Sensor4_SIO_DIFF           (* (reg8 *) Sensor4__SIO_DIFF)
#endif /* (Sensor4__SIO_CFG) */

/* Interrupt Registers */
#if defined(Sensor4__INTSTAT)
    #define Sensor4_INTSTAT            (* (reg8 *) Sensor4__INTSTAT)
    #define Sensor4_SNAP               (* (reg8 *) Sensor4__SNAP)
    
	#define Sensor4_0_INTTYPE_REG 		(* (reg8 *) Sensor4__0__INTTYPE)
#endif /* (Sensor4__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Sensor4_H */


/* [] END OF FILE */
