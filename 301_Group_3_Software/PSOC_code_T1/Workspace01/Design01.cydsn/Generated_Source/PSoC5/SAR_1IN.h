/*******************************************************************************
* File Name: SAR_1IN.h  
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

#if !defined(CY_PINS_SAR_1IN_H) /* Pins SAR_1IN_H */
#define CY_PINS_SAR_1IN_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "SAR_1IN_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 SAR_1IN__PORT == 15 && ((SAR_1IN__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    SAR_1IN_Write(uint8 value);
void    SAR_1IN_SetDriveMode(uint8 mode);
uint8   SAR_1IN_ReadDataReg(void);
uint8   SAR_1IN_Read(void);
void    SAR_1IN_SetInterruptMode(uint16 position, uint16 mode);
uint8   SAR_1IN_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the SAR_1IN_SetDriveMode() function.
     *  @{
     */
        #define SAR_1IN_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define SAR_1IN_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define SAR_1IN_DM_RES_UP          PIN_DM_RES_UP
        #define SAR_1IN_DM_RES_DWN         PIN_DM_RES_DWN
        #define SAR_1IN_DM_OD_LO           PIN_DM_OD_LO
        #define SAR_1IN_DM_OD_HI           PIN_DM_OD_HI
        #define SAR_1IN_DM_STRONG          PIN_DM_STRONG
        #define SAR_1IN_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define SAR_1IN_MASK               SAR_1IN__MASK
#define SAR_1IN_SHIFT              SAR_1IN__SHIFT
#define SAR_1IN_WIDTH              1u

/* Interrupt constants */
#if defined(SAR_1IN__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in SAR_1IN_SetInterruptMode() function.
     *  @{
     */
        #define SAR_1IN_INTR_NONE      (uint16)(0x0000u)
        #define SAR_1IN_INTR_RISING    (uint16)(0x0001u)
        #define SAR_1IN_INTR_FALLING   (uint16)(0x0002u)
        #define SAR_1IN_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define SAR_1IN_INTR_MASK      (0x01u) 
#endif /* (SAR_1IN__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SAR_1IN_PS                     (* (reg8 *) SAR_1IN__PS)
/* Data Register */
#define SAR_1IN_DR                     (* (reg8 *) SAR_1IN__DR)
/* Port Number */
#define SAR_1IN_PRT_NUM                (* (reg8 *) SAR_1IN__PRT) 
/* Connect to Analog Globals */                                                  
#define SAR_1IN_AG                     (* (reg8 *) SAR_1IN__AG)                       
/* Analog MUX bux enable */
#define SAR_1IN_AMUX                   (* (reg8 *) SAR_1IN__AMUX) 
/* Bidirectional Enable */                                                        
#define SAR_1IN_BIE                    (* (reg8 *) SAR_1IN__BIE)
/* Bit-mask for Aliased Register Access */
#define SAR_1IN_BIT_MASK               (* (reg8 *) SAR_1IN__BIT_MASK)
/* Bypass Enable */
#define SAR_1IN_BYP                    (* (reg8 *) SAR_1IN__BYP)
/* Port wide control signals */                                                   
#define SAR_1IN_CTL                    (* (reg8 *) SAR_1IN__CTL)
/* Drive Modes */
#define SAR_1IN_DM0                    (* (reg8 *) SAR_1IN__DM0) 
#define SAR_1IN_DM1                    (* (reg8 *) SAR_1IN__DM1)
#define SAR_1IN_DM2                    (* (reg8 *) SAR_1IN__DM2) 
/* Input Buffer Disable Override */
#define SAR_1IN_INP_DIS                (* (reg8 *) SAR_1IN__INP_DIS)
/* LCD Common or Segment Drive */
#define SAR_1IN_LCD_COM_SEG            (* (reg8 *) SAR_1IN__LCD_COM_SEG)
/* Enable Segment LCD */
#define SAR_1IN_LCD_EN                 (* (reg8 *) SAR_1IN__LCD_EN)
/* Slew Rate Control */
#define SAR_1IN_SLW                    (* (reg8 *) SAR_1IN__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define SAR_1IN_PRTDSI__CAPS_SEL       (* (reg8 *) SAR_1IN__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define SAR_1IN_PRTDSI__DBL_SYNC_IN    (* (reg8 *) SAR_1IN__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define SAR_1IN_PRTDSI__OE_SEL0        (* (reg8 *) SAR_1IN__PRTDSI__OE_SEL0) 
#define SAR_1IN_PRTDSI__OE_SEL1        (* (reg8 *) SAR_1IN__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define SAR_1IN_PRTDSI__OUT_SEL0       (* (reg8 *) SAR_1IN__PRTDSI__OUT_SEL0) 
#define SAR_1IN_PRTDSI__OUT_SEL1       (* (reg8 *) SAR_1IN__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define SAR_1IN_PRTDSI__SYNC_OUT       (* (reg8 *) SAR_1IN__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(SAR_1IN__SIO_CFG)
    #define SAR_1IN_SIO_HYST_EN        (* (reg8 *) SAR_1IN__SIO_HYST_EN)
    #define SAR_1IN_SIO_REG_HIFREQ     (* (reg8 *) SAR_1IN__SIO_REG_HIFREQ)
    #define SAR_1IN_SIO_CFG            (* (reg8 *) SAR_1IN__SIO_CFG)
    #define SAR_1IN_SIO_DIFF           (* (reg8 *) SAR_1IN__SIO_DIFF)
#endif /* (SAR_1IN__SIO_CFG) */

/* Interrupt Registers */
#if defined(SAR_1IN__INTSTAT)
    #define SAR_1IN_INTSTAT            (* (reg8 *) SAR_1IN__INTSTAT)
    #define SAR_1IN_SNAP               (* (reg8 *) SAR_1IN__SNAP)
    
	#define SAR_1IN_0_INTTYPE_REG 		(* (reg8 *) SAR_1IN__0__INTTYPE)
#endif /* (SAR_1IN__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_SAR_1IN_H */


/* [] END OF FILE */
