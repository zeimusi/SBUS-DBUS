#ifndef _SBUS__H_
#define _SBUS__H_

#include "main.h"
#include "string.h" 

#define RC_LEN 16
#define SBUS_LEN 25

/**
 * @brief 遥控器原始数据
 */
extern uint8_t RC_Buff[RC_LEN];

/**
 * @brief 遥控器转换后数据
 */
extern uint8_t SBUS_Buff[SBUS_LEN];

/**
 * @brief 遥控器数据结构体
 */
typedef struct {
    int16_t ch0;  //!<@brief 摇杆通道0数据
    int16_t ch1;  //!<@brief 摇杆通道1数据
    int16_t ch2;  //!<@brief 摇杆通道2数据
    int16_t ch3;  //!<@brief 摇杆通道3数据
    int8_t s1;    //!<@brief 开关1状态
    int8_t s2;    //!<@brief 开关2状态
} RC_Ctl_t;

extern RC_Ctl_t RC_CtrlData;

/**
 * @brief 遥控器数据转换函数
 * @param[in] rc_buff 遥控器原始数据 ,sbus_buff 遥控器转换后数据
 */
void DBUS_To_SBUS(uint8_t *rc_buff ,uint8_t *sbus_buff);

/**
 * @brief 遥控器数据解码函数
 * @param[in] sbus_buff 遥控器转换后数据
 */
void Remote_Rx(unsigned char *sbus_buff);

#endif

