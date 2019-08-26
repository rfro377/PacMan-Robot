/*******************************************************************************
* File Name: chA2.h  
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

#if !defined(CY_PINS_chA2_H) /* Pins chA2_H */
#define CY_PINS_chA2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "chA2_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 chA2__PORT == 15 && ((chA2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    chA2_Write(uint8 value);
void    chA2_SetDriveMode(uint8 mode);
uint8   chA2_ReadDataReg(void);
uint8   chA2_Read(void);
void    chA2_SetInterruptMode(uint16 position, uint16 mode);
uint8   chA2_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the chA2_SetDriveMode() function.
     *  @{
     */
        #define chA2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define chA2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define chA2_DM_RES_UP          PIN_DM_RES_UP
        #define chA2_DM_RES_DWN         PIN_DM_RES_DWN
        #define chA2_DM_OD_LO           PIN_DM_OD_LO
        #define chA2_DM_OD_HI           PIN_DM_OD_HI
        #define chA2_DM_STRONG          PIN_DM_STRONG
        #define chA2_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define chA2_MASK               chA2__MASK
#define chA2_SHIFT              chA2__SHIFT
#define chA2_WIDTH              1u

/* Interrupt constants */
#if defined(chA2__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in chA2_SetInterruptMode() function.
     *  @{
     */
        #define chA2_INTR_NONE      (uint16)(0x0000u)
        #define chA2_INTR_RISING    (uint16)(0x0001u)
        #define chA2_INTR_FALLING   (uint16)(0x0002u)
        #define chA2_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define chA2_INTR_MASK      (0x01u) 
#endif /* (chA2__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define chA2_PS                     (* (reg8 *) chA2__PS)
/* Data Register */
#define chA2_DR                     (* (reg8 *) chA2__DR)
/* Port Number */
#define chA2_PRT_NUM                (* (reg8 *) chA2__PRT) 
/* Connect to Analog Globals */                                                  
#define chA2_AG                     (* (reg8 *) chA2__AG)                       
/* Analog MUX bux enable */
#define chA2_AMUX                   (* (reg8 *) chA2__AMUX) 
/* Bidirectional Enable */                                                        
#define chA2_BIE                    (* (reg8 *) chA2__BIE)
/* Bit-mask for Aliased Register Access */
#define chA2_BIT_MASK               (* (reg8 *) chA2__BIT_MASK)
/* Bypass Enable */
#define chA2_BYP                    (* (reg8 *) chA2__BYP)
/* Port wide control signals */                                                   
#define chA2_CTL                    (* (reg8 *) chA2__CTL)
/* Drive Modes */
#define chA2_DM0                    (* (reg8 *) chA2__DM0) 
#define chA2_DM1                    (* (reg8 *) chA2__DM1)
#define chA2_DM2                    (* (reg8 *) chA2__DM2) 
/* Input Buffer Disable Override */
#define chA2_INP_DIS                (* (reg8 *) chA2__INP_DIS)
/* LCD Common or Segment Drive */
#define chA2_LCD_COM_SEG            (* (reg8 *) chA2__LCD_COM_SEG)
/* Enable Segment LCD */
#define chA2_LCD_EN                 (* (reg8 *) chA2__LCD_EN)
/* Slew Rate Control */
#define chA2_SLW                    (* (reg8 *) chA2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define chA2_PRTDSI__CAPS_SEL       (* (reg8 *) chA2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define chA2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) chA2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define chA2_PRTDSI__OE_SEL0        (* (reg8 *) chA2__PRTDSI__OE_SEL0) 
#define chA2_PRTDSI__OE_SEL1        (* (reg8 *) chA2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define chA2_PRTDSI__OUT_SEL0       (* (reg8 *) chA2__PRTDSI__OUT_SEL0) 
#define chA2_PRTDSI__OUT_SEL1       (* (reg8 *) chA2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define chA2_PRTDSI__SYNC_OUT       (* (reg8 *) chA2__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(chA2__SIO_CFG)
    #define chA2_SIO_HYST_EN        (* (reg8 *) chA2__SIO_HYST_EN)
    #define chA2_SIO_REG_HIFREQ     (* (reg8 *) chA2__SIO_REG_HIFREQ)
    #define chA2_SIO_CFG            (* (reg8 *) chA2__SIO_CFG)
    #define chA2_SIO_DIFF           (* (reg8 *) chA2__SIO_DIFF)
#endif /* (chA2__SIO_CFG) */

/* Interrupt Registers */
#if defined(chA2__INTSTAT)
    #define chA2_INTSTAT            (* (reg8 *) chA2__INTSTAT)
    #define chA2_SNAP               (* (reg8 *) chA2__SNAP)
    
	#define chA2_0_INTTYPE_REG 		(* (reg8 *) chA2__0__INTTYPE)
#endif /* (chA2__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_chA2_H */


/* [] END OF FILE */
