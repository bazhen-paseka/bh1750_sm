/**
* \file
* \version 1.0
* \author bazhen.levkovets
* \date 2020 
* \mail bazhen.info(at)gmail.com
*************************************************************************************
* \copyright	Bazhen Levkovets
* \copyright	Brovary, Kyiv region
* \copyright	Ukraine
*
*
*************************************************************************************
*
* \brief
*
*/

#ifndef BH1750_SM_H_INCLUDED
#define BH1750_SM_H_INCLUDED

/*
**************************************************************************
*								INCLUDE FILES
**************************************************************************
*/
	#include "main.h"
	#include "gpio.h"
	#include "usart.h"
	#include "stdio.h"
	#include <string.h>

/*
**************************************************************************
*								    DEFINES
**************************************************************************
*/

	#define BH1750_I2C_ADDR		0x23
/*
**************************************************************************
*								   DATA TYPES
**************************************************************************
*/

	typedef struct
	{
		I2C_HandleTypeDef 	*i2c;
		uint8_t 			 device_i2c_address;
	} bh1750_struct;

/*
**************************************************************************
*								GLOBAL VARIABLES
**************************************************************************
*/

/*
**************************************************************************
*									 MACRO'S
**************************************************************************
*/

/*
**************************************************************************
*                              FUNCTION PROTOTYPES
**************************************************************************
*/
	HAL_StatusTypeDef	BH1750_Init	( bh1750_struct * _h_bh1750 )		;
	uint16_t 			BH1750_Main	( bh1750_struct * _h_bh1750 )	 	;

#endif /* BH1750_SM_H_INCLUDED */


//	EXAMPLE
//
//	bh1750_struct h1_bh1750 =
//	{
//		.i2c = &hi2c1,
//		.device_i2c_address = BH1750_I2C_ADDR
//	};
//	//----------------------------------------------------------
//
//
//	HAL_StatusTypeDef res = BH1750_Init( &h1_bh1750 );
//	sprintf(DataChar,"\r\n\tBH1750 init status: %d;\r\n", (int)res);
//	HAL_UART_Transmit(&huart1, (uint8_t *)DataChar, strlen(DataChar), 100);
//
//	uint16_t lux_u16 = BH1750_Main( &h1_bh1750 );
//	sprintf(DataChar,"lux: %d; \r\n", (int)lux_u16);
//	HAL_UART_Transmit(&huart1, (uint8_t *)DataChar, strlen(DataChar), 100);
