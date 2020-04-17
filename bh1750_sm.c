/**
* \file
* \version 1.0
* \author bazhen.levkovets
** \date 2020
*
*************************************************************************************
* \copyright	Bazhen Levkovets
* \copyright	Brovary, Kyiv region
* \copyright	Ukraine
*
*************************************************************************************
*
* \brief
*
*/

/*
**************************************************************************
*							INCLUDE FILES
**************************************************************************
*/
	#include "bh1750_sm.h"
/*
**************************************************************************
*							LOCAL DEFINES
**************************************************************************
*/

/*
**************************************************************************
*							LOCAL CONSTANTS
**************************************************************************
*/
/*
**************************************************************************
*						    LOCAL DATA TYPES
**************************************************************************
*/
/*
**************************************************************************
*							  LOCAL TABLES
**************************************************************************
*/
/*
**************************************************************************
*								 MACRO'S
**************************************************************************
*/

/*
**************************************************************************
*						    GLOBAL VARIABLES
**************************************************************************
*/


/*
**************************************************************************
*                        LOCAL FUNCTION PROTOTYPES
**************************************************************************
*/
	
/*
**************************************************************************
*                           GLOBAL FUNCTIONS
**************************************************************************
*/

HAL_StatusTypeDef BH1750_init(bh1750_struct * _h_bh1750, bh1750_instruction_enum _instruct) {
	HAL_StatusTypeDef	op_res_td = HAL_OK;

	bh1750_instruction_enum 	bh1750_instruction	= bh1750_power_on;
	if (HAL_I2C_IsDeviceReady( _h_bh1750->i2c, _h_bh1750->device_i2c_address, 10, 100)== HAL_OK)	{
		op_res_td = op_res_td + HAL_I2C_Master_Transmit( _h_bh1750->i2c, _h_bh1750->device_i2c_address, &bh1750_instruction, 1,100);
	}

	if (HAL_I2C_IsDeviceReady( _h_bh1750->i2c, _h_bh1750->device_i2c_address, 10, 100)== HAL_OK)	{
		op_res_td = op_res_td + HAL_I2C_Master_Transmit( _h_bh1750->i2c, _h_bh1750->device_i2c_address, &_instruct, 1,100);
	}
	return op_res_td;
}
//************************************************************************

HAL_StatusTypeDef BH1750_get_lux (bh1750_struct *_h_bh1750, bh1750_instruction_enum _instruct, uint16_t *_result_lux_u16) {
	HAL_StatusTypeDef	op_res_td = HAL_OK;
	uint8_t				lux_buffer_u8[2]  ;

	if (HAL_I2C_IsDeviceReady( _h_bh1750->i2c, _h_bh1750->device_i2c_address, 10, 100)== HAL_OK)	{
		op_res_td = op_res_td + HAL_I2C_Master_Transmit( _h_bh1750->i2c, _h_bh1750->device_i2c_address, &_instruct, 1,100);
	}

	if (HAL_I2C_IsDeviceReady( _h_bh1750->i2c, _h_bh1750->device_i2c_address, 10, 100)== HAL_OK)	{
		op_res_td = op_res_td + HAL_I2C_Master_Receive(_h_bh1750->i2c, _h_bh1750->device_i2c_address, lux_buffer_u8, 2, 10);
	}

	*_result_lux_u16  = ((uint16_t)lux_buffer_u8[0]<<8) + lux_buffer_u8[1] ;

	return op_res_td;
}
//-------------------------------------------------------------------------------------------------

//************************************************************************

/*
**************************************************************************
*                           LOCAL FUNCTIONS
**************************************************************************
*/

//************************************************************************
