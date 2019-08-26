/*******************************************************************************
* File Name: chB1.h  
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

#if !defined(CY_PINS_chB1_H) /* Pins chB1_H */
#define CY_PINS_chB1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "chB1_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 chB1__PORT == 15 && ((chB1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    chB1_Write(uint8 value);
void    chB1_SetDriveMode(uint8 mode);
uint8   chB1_ReadDataReg(void);
uint8   chB1_Read(void);
void    chB1_SetInterruptMode(uint16 position, uint16 mode);
uint8   chB1_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the chB1_SetDriveMode() function.
     *  @{
     */
        #define chB1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define chB1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define chB1_DM_RES_UP          PIN_DM_RES_UP
        #define chB1_DM_RES_DWN         PIN_DM_RES_DWN
        #define chB1_DM_OD_LO           PIN_DM_OD_LO
        #define chB1_DM_OD_HI           PIN_DM_OD_HI
        #define chB1_DM_STRONG          PIN_DM_STRONG
        #define chB1_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define chB1_MASK               chB1__MASK
#define chB1_SHIFT              chB1__SHIFT
#define chB1_WIDTH              1u

/* Interrupt constants */
#if defined(chB1__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in chB1_SetInterruptMode() function.
     *  @{
     */
        #define chB1_INTR_NONE      (uint16)(0x0000u)
        #define chB1_INTR_RISING    (uint16)(0x0001u)
        #define chB1_INTR_FALLING   (uint16)(0x0002u)
        #define chB1_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define chB1_INTR_MASK      (0x01u) 
#endif /* (chB1__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define chB1_PS                     (* (reg8 *) chB1__PS)
/* Data Register */
#define chB1_DR                     (* (reg8 *) chB1__DR)
/* Port Number */
#define chB1_PRT_NUM                (* (reg8 *) chB1__PRT) 
/* Connect to Analog Globals */                                                  
#define chB1_AG                     (* (reg8 *) chB1__AG)                       
/* Analog MUX bux enable */
#define chB1_AMUX                   (* (reg8 *) chB1__AMUX) 
/* Bidirectional Enable */                                                        
#define chB1_BIE                    (* (reg8 *) chB1__BIE)
/* Bit-mask for Aliased Register Access */
#define chB1_BIT_MASK               (* (reg8 *) chB1__BIT_MASK)
/* Bypass Enable */
#define chB1_BYP                    (* (reg8 *) chB1__BYP)
/* Port wide control signals */                                                   
#define chB1_CTL                    (* (reg8 *) chB1__CTL)
/* Drive Modes */
#define chB1_DM0                    (* (reg8 *) chB1__DM0) 
#define chB1_DM1                    (* (reg8 *) chB1__DM1)
#define chB1_DM2                    (* (reg8 *) chB1__DM2) 
/* Input Buffer Disable Override */
#define chB1_INP_DIS                (* (reg8 *) chB1__INP_DIS)
/* LCD Common or Segment Drive */
#define chB1_LCD_COM_SEG            (* (reg8 *) chB1__LCD_COM_SEG)
/* Enable Segment LCD */
#define chB1_LCD_EN                 (* (reg8 *) chB1__LCD_EN)
/* Slew Rate Control */
#define chB1_SLW                    (* (reg8 *) chB1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define chB1_PRTDSI__CAPS_SEL       (* (reg8 *) chB1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define chB1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) chB1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define chB1_PRTDSI__OE_SEL0        (* (reg8 *) chB1__PRTDSI__OE_SEL0) 
#define chB1_PRTDSI__OE_SEL1        (* (reg8 *) chB1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define chB1_PRTDSI__OUT_SEL0       (* (reg8 *) chB1__PRTDSI__OUT_SEL0) 
#define chB1_PRTDSI__OUT_SEL1       (* (reg8 *) chB1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define chB1_PRTDSI__SYNC_OUT       (* (reg8 *) chB1__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(chB1__SIO_CFG)
    #define chB1_SIO_HYST_EN        (* (reg8 *) chB1__SIO_HYST_EN)
    #define chB1_SIO_REG_HIFREQ     (* (reg8 *) chB1__SIO_REG_HIFREQ)
    #define chB1_SIO_CFG            (* (reg8 *) chB1__SIO_CFG)
    #define chB1_SIO_DIFF           (* (reg8 *) chB1__SIO_DIFF)
#endif /* (chB1__SIO_CFG) */

/* Interrupt Registers */
#if defined(chB1__INTSTAT)
    #define chB1_INTSTAT            (* (reg8 *) chB1__INTSTAT)
    #define chB1_SNAP               (* (reg8 *) chB1__SNAP)
    
	#define chB1_0_INTTYPE_REG 		(* (reg8 *) chB1__0__INTTYPE)
#endif /* (chB1__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_chB1_H */


/* [] END OF FILE */
