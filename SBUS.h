#ifndef _SBUS__H_
#define _SBUS__H_

#include "main.h"
#include "string.h" 

#define RC_LEN 16
#define SBUS_LEN 25

/**
 * @brief ң����ԭʼ����
 */
extern uint8_t RC_Buff[RC_LEN];

/**
 * @brief ң����ת��������
 */
extern uint8_t SBUS_Buff[SBUS_LEN];

/**
 * @brief ң�������ݽṹ��
 */
typedef struct {
    int16_t ch0;  //!<@brief ҡ��ͨ��0����
    int16_t ch1;  //!<@brief ҡ��ͨ��1����
    int16_t ch2;  //!<@brief ҡ��ͨ��2����
    int16_t ch3;  //!<@brief ҡ��ͨ��3����
    int8_t s1;    //!<@brief ����1״̬
    int8_t s2;    //!<@brief ����2״̬
} RC_Ctl_t;

extern RC_Ctl_t RC_CtrlData;

/**
 * @brief ң��������ת������
 * @param[in] rc_buff ң����ԭʼ���� ,sbus_buff ң����ת��������
 */
void DBUS_To_SBUS(uint8_t *rc_buff ,uint8_t *sbus_buff);

/**
 * @brief ң�������ݽ��뺯��
 * @param[in] sbus_buff ң����ת��������
 */
void Remote_Rx(unsigned char *sbus_buff);

#endif

