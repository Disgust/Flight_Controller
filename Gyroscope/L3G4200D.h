
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __L3G4200D_DRIVER__H
#define __L3G4200D_DRIVER__H

#include <stdint.h>
#include "../Assign.h"
#include "../Macro.h"
#include "../Communication_mega328.h"

/* Includes ------------------------------------------------------------------*/

#define I2C_COMMUNICATION       0
#define SPI_COMMUNICATION       1
/* Exported common structure --------------------------------------------------------*/

#ifndef __SHARED__TYPES
#define __SHARED__TYPES

typedef enum {
  MEMS_SUCCESS				=		0x01,
  MEMS_ERROR				=		0x00	
} status_t;

typedef enum {
  MEMS_ENABLE				=		0x01,
  MEMS_DISABLE				=		0x00	
} memsState_t;

#endif /*__SHARED__TYPES*/

typedef enum {  
  L3G4200D_ODR_95Hz_BW_12_5               =		0x00,
  L3G4200D_ODR_95Hz_BW_25			=		0x01,		
  L3G4200D_ODR_190Hz_BW_12_5              =		0x04,
  L3G4200D_ODR_190Hz_BW_25		=		0x05,
  L3G4200D_ODR_190Hz_BW_50		=		0x06,
  L3G4200D_ODR_190Hz_BW_70		=		0x07,	
  L3G4200D_ODR_380Hz_BW_20		=		0x08,
  L3G4200D_ODR_380Hz_BW_25		=		0x09,
  L3G4200D_ODR_380Hz_BW_50		=		0x0A,
  L3G4200D_ODR_380Hz_BW_110               =		0x0B,	
  L3G4200D_ODR_760Hz_BW_30		=		0x0C,
  L3G4200D_ODR_760Hz_BW_35		=		0x0D,
  L3G4200D_ODR_760Hz_BW_50		=		0x0E,
  L3G4200D_ODR_760Hz_BW_110     	        =		0x0F
} L3G4200D_ODR_t;

typedef enum {
  L3G4200D_POWER_DOWN                     =		0x00,
  L3G4200D_SLEEP 				=		0x01,
  L3G4200D_NORMAL				=		0x02
} L3G4200D_Mode_t;

typedef enum {
  L3G4200D_HPM_NORMAL_MODE_RES           =               0x00,
  L3G4200D_HPM_REF_SIGNAL                =               0x01,
  L3G4200D_HPM_NORMAL_MODE               =               0x02,
  L3G4200D_HPM_AUTORESET_INT             =               0x03
} L3G4200D_HPFMode_t;

typedef enum {
  L3G4200D_HPFCF_0                       =               0x00,
  L3G4200D_HPFCF_1                       =               0x01,
  L3G4200D_HPFCF_2                       = 	       0x02,
  L3G4200D_HPFCF_3                       =               0x03,
  L3G4200D_HPFCF_4                       =               0x04,
  L3G4200D_HPFCF_5                       =               0x05,
  L3G4200D_HPFCF_6                       =               0x06,
  L3G4200D_HPFCF_7                       =               0x07,
  L3G4200D_HPFCF_8                       =               0x08,
  L3G4200D_HPFCF_9                       =               0x09
} L3G4200D_HPFCutOffFreq_t;

typedef enum {
  L3G4200D_PUSH_PULL                    =				0x00,
  L3G4200D_OPEN_DRAIN                   =               0x01  
} L3G4200D_IntPinMode_t;

typedef enum {
  L3G4200D_FULLSCALE_250                =               0x00,
  L3G4200D_FULLSCALE_500                =               0x01,
  L3G4200D_FULLSCALE_2000               =               0x02	
} L3G4200D_Fullscale_t;

typedef enum {
  L3G4200D_BLE_LSB						=				0x00,
  L3G4200D_BLE_MSB						=				0x01
} L3G4200D_Endianess_t;

typedef enum {
  L3G4200D_SPI_4_WIRE                   =				0x00,
  L3G4200D_SPI_3_WIRE                   =				0x01
} L3G4200D_SPIMode_t;

typedef enum {
  L3G4200D_FIFO_DISABLE                 =				0x05,
  L3G4200D_FIFO_BYPASS_MODE             =				0x00,
  L3G4200D_FIFO_MODE                    =				0x01,
  L3G4200D_FIFO_STREAM_MODE             =				0x02,
  L3G4200D_FIFO_STREAM_TO_FIFO_MODE     =				0x03,
  L3G4200D_FIFO_BYPASS_TO_STREAM_MODE   =				0x04    
} L3G4200D_FifoMode_t;

typedef enum {
  L3G4200D_NONE                         =				0x00,
  L3G4200D_HPF                          =				0x01,
  L3G4200D_LPF2                         =				0x02,
  L3G4200D_HPFLPF2                      =				0x03
} L3G4200D_HPF_LPF2_Enable;

typedef enum {
  L3G4200D_THS_X                        =				0x00,
  L3G4200D_THS_Y                        =				0x01,  
  L3G4200D_THS_Z                        =				0x02
} L3G4200D_IntThsAxis;

/**************CONTROL REGISTERS*****************/

#define L3G4200D_ADDRESS								0xD2

/***************CTRL1***************/
#define L3G4200D_CTRL_REG1								0x20
#define L3G4200D_ODR_BIT								4
#define L3G4200D_PD										3
#define L3G4200D_ZEN									2
#define L3G4200D_YEN									1
#define L3G4200D_XEN									0
#define L3G4200D_X_ENABLE                               0x02
#define L3G4200D_Y_ENABLE                               0x01
#define L3G4200D_Z_ENABLE                               0x04

/***************CTRL2***************/
#define L3G4200D_CTRL_REG2								0x21
#define L3G4200D_HPM									4
#define L3G4200D_HPFC3									3
#define L3G4200D_HPFC2									2
#define L3G4200D_HPFC1									1
#define L3G4200D_HPFC0									0

/***************CTRL3***************/
#define L3G4200D_CTRL_REG3								0x22
#define L3G4200D_I1_INT									7
#define L3G4200D_I1_BOOT								6
#define L3G4200D_H_LACTIVE								5
#define L3G4200D_PP_OD									4
#define L3G4200D_I2_DRDY								3
#define L3G4200D_I2_WTM									2
#define L3G4200D_I2_ORUN								1
#define L3G4200D_I2_EMPTY								0
#define L3G4200D_I1_ON_PIN_INT1_ENABLE                  0x80
#define L3G4200D_I1_ON_PIN_INT1_DISABLE                 0x00
#define L3G4200D_I1_BOOT_ON_INT1_ENABLE                 0x40
#define L3G4200D_I1_BOOT_ON_INT1_DISABLE                0x00
#define L3G4200D_INT1_ACTIVE_HIGH                       0x00
#define L3G4200D_INT1_ACTIVE_LOW                        0x20
#define L3G4200D_I2_DRDY_ON_INT2_ENABLE                 0x08
#define L3G4200D_I2_DRDY_ON_INT2_DISABLE                0x00
#define L3G4200D_WTM_ON_INT2_ENABLE                     0x04
#define L3G4200D_WTM_ON_INT2_DISABLE                    0x00
#define L3G4200D_OVERRUN_ON_INT2_ENABLE                 0x02
#define L3G4200D_OVERRUN_ON_INT2_DISABLE                0x00
#define L3G4200D_EMPTY_ON_INT2_ENABLE                   0x01
#define L3G4200D_EMPTY_ON_INT2_DISABLE                  0x00

/***************CTRL4***************/
#define L3G4200D_CTRL_REG4								0x23
#define L3G4200D_BDU									7
#define L3G4200D_BLE									6
#define L3G4200D_FS										4
#define L3G4200D_SIM									0

/***************CTRL5***************/
#define L3G4200D_CTRL_REG5								0x24
#define L3G4200D_FIFO_EN                                6
#define L3G4200D_HPEN                                   4
#define L3G4200D_INT1_SEL1                              3
#define L3G4200D_INT1_SEL0                              2
#define L3G4200D_OUT_SEL1                               1
#define L3G4200D_OUT_SEL0                               0

/**************GYROSCOPE INTERRUPT REGISTERS***************/
#define L3G4200D_INT1_CFG								0x30
#define L3G4200D_INT1_SRC								0x31
#define L3G4200D_INT1_THS_XH							0x32
#define L3G4200D_INT1_THS_XL							0x33
#define L3G4200D_INT1_THS_YH							0x34
#define L3G4200D_INT1_THS_YL							0x35
#define L3G4200D_INT1_THS_ZH							0x36
#define L3G4200D_INT1_THS_ZL							0x37
#define L3G4200D_INT1_DURATION							0x38
#define L3G4200D_LIR                                    6
#define L3G4200D_ANDOR                                  7
#define L3G4200D_ZHIE                                   5
#define L3G4200D_ZLIE                                   4
#define L3G4200D_YHIE                                   3
#define L3G4200D_YLIE                                   2
#define L3G4200D_XHIE                                   1
#define L3G4200D_XLIE                                   0
#define L3G4200D_INT1_AND                               0x80
#define L3G4200D_INT1_OR                                0x00
#define L3G4200D_INT1_LIR_ENABLE                        0x40
#define L3G4200D_INT1_LIR_DISABLE                       0x00
#define L3G4200D_INT1_ZHIE_ENABLE                       0x20
#define L3G4200D_INT1_ZHIE_DISABLE                      0x00
#define L3G4200D_INT1_ZLIE_ENABLE                       0x10
#define L3G4200D_INT1_ZLIE_DISABLE                      0x00
#define L3G4200D_INT1_YHIE_ENABLE                       0x08
#define L3G4200D_INT1_YHIE_DISABLE                      0x00
#define L3G4200D_INT1_YLIE_ENABLE                       0x04
#define L3G4200D_INT1_YLIE_DISABLE                      0x00
#define L3G4200D_INT1_XHIE_ENABLE                       0x02
#define L3G4200D_INT1_XHIE_DISABLE                      0x00
#define L3G4200D_INT1_XLIE_ENABLE                       0x01
#define L3G4200D_INT1_XLIE_DISABLE                      0x00

/**********GYROSCOPE: STATUS AND OUTPUT REGISTERS***********/
//OUTPUT REGISTER
#define L3G4200D_OUT_X_L								0x28
#define L3G4200D_OUT_X_H								0x29
#define L3G4200D_OUT_Y_L								0x2A
#define L3G4200D_OUT_Y_H								0x2B
#define L3G4200D_OUT_Z_L								0x2C
#define L3G4200D_OUT_Z_H								0x2D
#define L3G4200D_STATUS_REG                             0x27
#define L3G4200D_STATUS_REG_ZYXOR                       0x07    // 1	:	new data set has over written the previous one
							// 0	:	no overrun has occurred (default)	
#define L3G4200D_STATUS_REG_ZOR                         0x06    // 0	:	no overrun has occurred (default)
							// 1	:	new Z-axis data has over written the previous one
#define L3G4200D_STATUS_REG_YOR                         0x05    // 0	:	no overrun has occurred (default)
							// 1	:	new Y-axis data has over written the previous one
#define L3G4200D_STATUS_REG_XOR                         0x04    // 0	:	no overrun has occurred (default)
							// 1	:	new X-axis data has over written the previous one
#define L3G4200D_STATUS_REG_ZYXDA                       0x03    // 0	:	a new set of data is not yet avvious one
                                                        // 1	:	a new set of data is available 
#define L3G4200D_STATUS_REG_ZDA                         0x02    // 0	:	a new data for the Z-Axis is not availvious one
                                                        // 1	:	a new data for the Z-Axis is available
#define L3G4200D_STATUS_REG_YDA                         0x01    // 0	:	a new data for the Y-Axis is not available
                                                        // 1	:	a new data for the Y-Axis is available
#define STATUS_REG_XDA                         			0x00    // 0	:	a new data for the X-Axis is not available

#define L3G4200D_DATAREADY_BIT                          L3G4200D_STATUS_REG_ZYXDA

#define L3G4200D_I_AM_L3G4200D							0xD4

/*************GYROSCOPE FIFO CONTROL REGISTER**************/
#define L3G4200D_FM0                                    5
#define L3G4200D_FIFO_CTRL_REG                          0x2E
#define L3G4200D_FIFO_SRC_REG							0x2F

/* Exported functions --------------------------------------------------------*/
/**********Sensor Configuration Functions***********/
void L3G4200D_SetODR(L3G4200D_ODR_t);
void L3G4200D_SetMode(L3G4200D_Mode_t);
void L3G4200D_SetAxis(uint8_t);
void L3G4200D_SetFullScale(L3G4200D_Fullscale_t);
void L3G4200D_SetBDU(memsState_t);
void L3G4200D_SetBLE(L3G4200D_Endianess_t);
void L3G4200D_SetSPIInterface(L3G4200D_SPIMode_t);

/***************Filtering Functions****************/
void L3G4200D_SetHPFMode(L3G4200D_HPFMode_t);
void L3G4200D_SetHPFCutOFF(L3G4200D_HPFCutOffFreq_t);
void L3G4200D_HPFEnable(memsState_t);
void L3G4200D_SetOutputDataAndFifoFilters(L3G4200D_HPF_LPF2_Enable);
void L3G4200D_SetInt1Filters(L3G4200D_HPF_LPF2_Enable);

/***************Interrupt Functions****************/
void L3G4200D_SetIntPinMode(L3G4200D_IntPinMode_t);
void L3G4200D_SetInt1Pin(uint8_t);
void L3G4200D_SetInt2Pin(uint8_t);
void L3G4200D_Int1LatchEnable(memsState_t);
void L3G4200D_ResetInt1Latch(void);
void L3G4200D_SetIntConfiguration(uint8_t);
void L3G4200D_SetInt1Threshold(L3G4200D_IntThsAxis, uint16_t);
void L3G4200D_SetInt1Duration(uint8_t);

/*****************FIFO Functions******************/
void L3G4200D_FIFOModeEnable(L3G4200D_FifoMode_t);
void L3G4200D_SetWaterMark(uint8_t);

/****************Reading Functions*****************/
void L3G4200D_GetSatusReg(uint8_t *);
void L3G4200D_GetAngRateRaw(volatile vect_t *);
void L3G4200D_GetFifoSourceReg(uint8_t *);
void L3G4200D_GetInt1Src(uint8_t *);


/*********************Generic*********************/
uint8_t L3G4200D_ReadReg(uint8_t);
void L3G4200D_WriteReg(uint8_t, uint8_t);

#endif /* __L3G4200D_H */



