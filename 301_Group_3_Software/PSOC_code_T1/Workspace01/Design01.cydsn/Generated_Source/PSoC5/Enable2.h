/*******************************************************************************
* File Name: Enable2.h  
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

#if !defined(CY_PINS_Enable2_H) /* Pins Enable2_H */
#define CY_PINS_Enable2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Enable2_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Enable2__PORT == 15 && ((Enable2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Enable2_Write(uint8 value);
void    Enable2_SetDriveMode(uint8 mode);
uint8   Enable2_ReadDataReg(void);
uint8   Enable2_Read(void);
void    Enable2_SetInterruptMode(uint16 position, uint16 mode);
uint8   Enable2_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Enable2_SetDriveMode() function.
     *  @{
     */
        #define Enable2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Enable2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Enable2_DM_RES_UP          PIN_DM_RES_UP
        #define Enable2_DM_RES_DWN         PIN_DM_RES_DWN
        #define Enable2_DM_OD_LO           PIN_DM_OD_LO
        #define Enable2_DM_OD_HI           PIN_DM_OD_HI
        #define Enable2_DM_STRONG          PIN_DM_STRONG
        #define Enable2_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Enable2_MASK               Enable2__MASK
#define Enable2_SHIFT              Enable2__SHIFT
#define Enable2_WIDTH              1u

/* Interrupt constants */
#if defined(Enable2__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Enable2_SetInterruptMode() function.
     *  @{
     */
        #define Enable2_INTR_NONE      (uint16)(0x0000u)
        #define Enable2_INTR_RISING    (uint16)(0x0001u)
        #define Enable2_INTR_FALLING   (uint16)(0x0002u)
        #define Enable2_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Enable2_INTR_MASK      (0x01u) 
#endif /* (Enable2__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Enable2_PS                     (* (reg8 *) Enable2__PS)
/* Data Register */
#define Enable2_DR                     (* (reg8 *) Enable2__DR)
/* Port Number */
#define Enable2_PRT_NUM                (* (reg8 *) Enable2__PRT) 
/* Connect to Analog Globals */                                                  
#define Enable2_AG                     (* (reg8 *) Enable2__AG)                       
/* Analog MUX bux enable */
#define Enable2_AMUX                   (* (reg8 *) Enable2__AMUX) 
/* Bidirectional Enable */                                                        
#define Enable2_BIE                    (* (reg8 *) Enable2__BIE)
/* Bit-mask for Aliased Register Access */
#define Enable2_BIT_MASK               (* (reg8 *) Enable2__BIT_MASK)
/* Bypass Enable */
#define Enable2_BYP                    (* (reg8 *) Enable2__BYP)
/* Port wide control signals */                                                   
#define Enable2_CTL                    (* (reg8 *) Enable2__CTL)
/* Drive Modes */
#define Enable2_DM0                    (* (reg8 *) Enable2__DM0) 
#define Enable2_DM1                    (* (reg8 *) Enable2__DM1)
#define Enable2_DM2                    (* (reg8 *) Enable2__DM2) 
/* Input Buffer Disable Override */
#define Enable2_INP_DIS                (* (reg8 *) Enable2__INP_DIS)
/* LCD Common or Segment Drive */
#define Enable2_LCD_COM_SEG            (* (reg8 *) Enable2__LCD_COM_SEG)
/* Enable Segment LCD */
#define Enable2_LCD_EN                 (* (reg8 *) Enable2__LCD_EN)
/* Slew Rate Control */
#define Enable2_SLW                    (* (reg8 *) Enable2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Enable2_PRTDSI__CAPS_SEL       (* (reg8 *) Enable2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Enable2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Enable2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Enable2_PRTDSI__OE_SEL0        (* (reg8 *) Enable2__PRTDSI__OE_SEL0) 
#define Enable2_PRTDSI__OE_SEL1        (* (reg8 *) Enable2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Enable2_PRTDSI__OUT_SEL0       (* (reg8 *) Enable2__PRTDSI__OUT_SEL0) 
#define Enable2_PRTDSI__OUT_SEL1       (* (reg8 *) Enable2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Enable2_PRTDSI__SYNC_OUT       (* (reg8 *) Enable2__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Enable2__SIO_CFG)
    #define Enable2_SIO_HYST_EN        (* (reg8 *) Enable2__SIO_HYST_EN)
    #define Enable2_SIO_REG_HIFREQ     (* (reg8 *) Enable2__SIO_REG_HIFREQ)
    #define Enable2_SIO_CFG            (* (reg8 *) Enable2__SIO_CFG)
    #define Enable2_SIO_DIFF           (* (reg8 *) Enable2__SIO_DIFF)
#endif /* (Enable2__SIO_CFG) */

/* Interrupt Registers */
#if defined(Enable2__INTSTAT)
    #define Enable2_INTSTAT            (* (reg8 *) Enable2__INTSTAT)
    #define Enable2_SNAP               (* (reg8 *) Enable2__SNAP)
    
	#define Enable2_0_INTTYPE_REG 		(* (reg8 *) Enable2__0__INTTYPE)
#endif /* (Enable2__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Enable2_H */


/* [] END OF FILE */
