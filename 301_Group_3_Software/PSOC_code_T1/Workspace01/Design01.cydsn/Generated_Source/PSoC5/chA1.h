/*******************************************************************************
* File Name: chA1.h  
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

#if !defined(CY_PINS_chA1_H) /* Pins chA1_H */
#define CY_PINS_chA1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "chA1_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 chA1__PORT == 15 && ((chA1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    chA1_Write(uint8 value);
void    chA1_SetDriveMode(uint8 mode);
uint8   chA1_ReadDataReg(void);
uint8   chA1_Read(void);
void    chA1_SetInterruptMode(uint16 position, uint16 mode);
uint8   chA1_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the chA1_SetDriveMode() function.
     *  @{
     */
        #define chA1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define chA1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define chA1_DM_RES_UP          PIN_DM_RES_UP
        #define chA1_DM_RES_DWN         PIN_DM_RES_DWN
        #define chA1_DM_OD_LO           PIN_DM_OD_LO
        #define chA1_DM_OD_HI           PIN_DM_OD_HI
        #define chA1_DM_STRONG          PIN_DM_STRONG
        #define chA1_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define chA1_MASK               chA1__MASK
#define chA1_SHIFT              chA1__SHIFT
#define chA1_WIDTH              1u

/* Interrupt constants */
#if defined(chA1__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in chA1_SetInterruptMode() function.
     *  @{
     */
        #define chA1_INTR_NONE      (uint16)(0x0000u)
        #define chA1_INTR_RISING    (uint16)(0x0001u)
        #define chA1_INTR_FALLING   (uint16)(0x0002u)
        #define chA1_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define chA1_INTR_MASK      (0x01u) 
#endif /* (chA1__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define chA1_PS                     (* (reg8 *) chA1__PS)
/* Data Register */
#define chA1_DR                     (* (reg8 *) chA1__DR)
/* Port Number */
#define chA1_PRT_NUM                (* (reg8 *) chA1__PRT) 
/* Connect to Analog Globals */                                                  
#define chA1_AG                     (* (reg8 *) chA1__AG)                       
/* Analog MUX bux enable */
#define chA1_AMUX                   (* (reg8 *) chA1__AMUX) 
/* Bidirectional Enable */                                                        
#define chA1_BIE                    (* (reg8 *) chA1__BIE)
/* Bit-mask for Aliased Register Access */
#define chA1_BIT_MASK               (* (reg8 *) chA1__BIT_MASK)
/* Bypass Enable */
#define chA1_BYP                    (* (reg8 *) chA1__BYP)
/* Port wide control signals */                                                   
#define chA1_CTL                    (* (reg8 *) chA1__CTL)
/* Drive Modes */
#define chA1_DM0                    (* (reg8 *) chA1__DM0) 
#define chA1_DM1                    (* (reg8 *) chA1__DM1)
#define chA1_DM2                    (* (reg8 *) chA1__DM2) 
/* Input Buffer Disable Override */
#define chA1_INP_DIS                (* (reg8 *) chA1__INP_DIS)
/* LCD Common or Segment Drive */
#define chA1_LCD_COM_SEG            (* (reg8 *) chA1__LCD_COM_SEG)
/* Enable Segment LCD */
#define chA1_LCD_EN                 (* (reg8 *) chA1__LCD_EN)
/* Slew Rate Control */
#define chA1_SLW                    (* (reg8 *) chA1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define chA1_PRTDSI__CAPS_SEL       (* (reg8 *) chA1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define chA1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) chA1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define chA1_PRTDSI__OE_SEL0        (* (reg8 *) chA1__PRTDSI__OE_SEL0) 
#define chA1_PRTDSI__OE_SEL1        (* (reg8 *) chA1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define chA1_PRTDSI__OUT_SEL0       (* (reg8 *) chA1__PRTDSI__OUT_SEL0) 
#define chA1_PRTDSI__OUT_SEL1       (* (reg8 *) chA1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define chA1_PRTDSI__SYNC_OUT       (* (reg8 *) chA1__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(chA1__SIO_CFG)
    #define chA1_SIO_HYST_EN        (* (reg8 *) chA1__SIO_HYST_EN)
    #define chA1_SIO_REG_HIFREQ     (* (reg8 *) chA1__SIO_REG_HIFREQ)
    #define chA1_SIO_CFG            (* (reg8 *) chA1__SIO_CFG)
    #define chA1_SIO_DIFF           (* (reg8 *) chA1__SIO_DIFF)
#endif /* (chA1__SIO_CFG) */

/* Interrupt Registers */
#if defined(chA1__INTSTAT)
    #define chA1_INTSTAT            (* (reg8 *) chA1__INTSTAT)
    #define chA1_SNAP               (* (reg8 *) chA1__SNAP)
    
	#define chA1_0_INTTYPE_REG 		(* (reg8 *) chA1__0__INTTYPE)
#endif /* (chA1__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_chA1_H */


/* [] END OF FILE */
