/*******************************************************************************
* File Name: chB2.h  
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

#if !defined(CY_PINS_chB2_H) /* Pins chB2_H */
#define CY_PINS_chB2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "chB2_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 chB2__PORT == 15 && ((chB2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    chB2_Write(uint8 value);
void    chB2_SetDriveMode(uint8 mode);
uint8   chB2_ReadDataReg(void);
uint8   chB2_Read(void);
void    chB2_SetInterruptMode(uint16 position, uint16 mode);
uint8   chB2_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the chB2_SetDriveMode() function.
     *  @{
     */
        #define chB2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define chB2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define chB2_DM_RES_UP          PIN_DM_RES_UP
        #define chB2_DM_RES_DWN         PIN_DM_RES_DWN
        #define chB2_DM_OD_LO           PIN_DM_OD_LO
        #define chB2_DM_OD_HI           PIN_DM_OD_HI
        #define chB2_DM_STRONG          PIN_DM_STRONG
        #define chB2_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define chB2_MASK               chB2__MASK
#define chB2_SHIFT              chB2__SHIFT
#define chB2_WIDTH              1u

/* Interrupt constants */
#if defined(chB2__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in chB2_SetInterruptMode() function.
     *  @{
     */
        #define chB2_INTR_NONE      (uint16)(0x0000u)
        #define chB2_INTR_RISING    (uint16)(0x0001u)
        #define chB2_INTR_FALLING   (uint16)(0x0002u)
        #define chB2_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define chB2_INTR_MASK      (0x01u) 
#endif /* (chB2__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define chB2_PS                     (* (reg8 *) chB2__PS)
/* Data Register */
#define chB2_DR                     (* (reg8 *) chB2__DR)
/* Port Number */
#define chB2_PRT_NUM                (* (reg8 *) chB2__PRT) 
/* Connect to Analog Globals */                                                  
#define chB2_AG                     (* (reg8 *) chB2__AG)                       
/* Analog MUX bux enable */
#define chB2_AMUX                   (* (reg8 *) chB2__AMUX) 
/* Bidirectional Enable */                                                        
#define chB2_BIE                    (* (reg8 *) chB2__BIE)
/* Bit-mask for Aliased Register Access */
#define chB2_BIT_MASK               (* (reg8 *) chB2__BIT_MASK)
/* Bypass Enable */
#define chB2_BYP                    (* (reg8 *) chB2__BYP)
/* Port wide control signals */                                                   
#define chB2_CTL                    (* (reg8 *) chB2__CTL)
/* Drive Modes */
#define chB2_DM0                    (* (reg8 *) chB2__DM0) 
#define chB2_DM1                    (* (reg8 *) chB2__DM1)
#define chB2_DM2                    (* (reg8 *) chB2__DM2) 
/* Input Buffer Disable Override */
#define chB2_INP_DIS                (* (reg8 *) chB2__INP_DIS)
/* LCD Common or Segment Drive */
#define chB2_LCD_COM_SEG            (* (reg8 *) chB2__LCD_COM_SEG)
/* Enable Segment LCD */
#define chB2_LCD_EN                 (* (reg8 *) chB2__LCD_EN)
/* Slew Rate Control */
#define chB2_SLW                    (* (reg8 *) chB2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define chB2_PRTDSI__CAPS_SEL       (* (reg8 *) chB2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define chB2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) chB2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define chB2_PRTDSI__OE_SEL0        (* (reg8 *) chB2__PRTDSI__OE_SEL0) 
#define chB2_PRTDSI__OE_SEL1        (* (reg8 *) chB2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define chB2_PRTDSI__OUT_SEL0       (* (reg8 *) chB2__PRTDSI__OUT_SEL0) 
#define chB2_PRTDSI__OUT_SEL1       (* (reg8 *) chB2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define chB2_PRTDSI__SYNC_OUT       (* (reg8 *) chB2__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(chB2__SIO_CFG)
    #define chB2_SIO_HYST_EN        (* (reg8 *) chB2__SIO_HYST_EN)
    #define chB2_SIO_REG_HIFREQ     (* (reg8 *) chB2__SIO_REG_HIFREQ)
    #define chB2_SIO_CFG            (* (reg8 *) chB2__SIO_CFG)
    #define chB2_SIO_DIFF           (* (reg8 *) chB2__SIO_DIFF)
#endif /* (chB2__SIO_CFG) */

/* Interrupt Registers */
#if defined(chB2__INTSTAT)
    #define chB2_INTSTAT            (* (reg8 *) chB2__INTSTAT)
    #define chB2_SNAP               (* (reg8 *) chB2__SNAP)
    
	#define chB2_0_INTTYPE_REG 		(* (reg8 *) chB2__0__INTTYPE)
#endif /* (chB2__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_chB2_H */


/* [] END OF FILE */
