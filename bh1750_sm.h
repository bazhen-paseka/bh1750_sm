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

	#include "bh1750_local_config.h"

/*
**************************************************************************
*								    DEFINES
**************************************************************************
*/

typedef enum
{
	bh1750_power_down					=	0b00000000	,
	bh1750_power_on						=	0b00000001	,
	bh1750_power_reset					=	0b00000111	,
	bh1750_continuously_h_resolution	=	0b00010000	,
	bh1750_continuously_h2_resolution	=	0b00010001	,
	bh1750_continuously_l_resolution	=	0b00010011	,
	bh1750_one_time_h_resolutione		=	0b00100000	,
	bh1750_one_time_h2_resolutione		=	0b00100001	,
	bh1750_one_time_l_resolutione		=	0b00100011	,
}	bh1750_instruction_enum;

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
	HAL_StatusTypeDef	BH1750_init		( bh1750_struct * _h_bh1750, bh1750_instruction_enum _instruct );
	HAL_StatusTypeDef	BH1750_get_lux	( bh1750_struct * _h_bh1750, bh1750_instruction_enum _instruct, uint16_t * _result_lux_u16 );

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
