#include "SBUS.h"

RC_Ctl_t RC_CtrlData = {1024, 1024, 1024, 1024, 1, 1};     //!<@brief 遥控器数据初始化

uint8_t RC_Buff[RC_LEN];
uint8_t SBUS_Buff[SBUS_LEN]={0};

void DBUS_To_SBUS(uint8_t *rc_buff ,uint8_t *sbus_buff)
{
	if(rc_buff == NULL || sbus_buff == NULL)
	{
		return;
	}
	sbus_buff[0] = 0x0F;
	
	memcpy(&sbus_buff[1], rc_buff, sizeof(&rc_buff));
	
	sbus_buff[23] = 0x00;
	sbus_buff[24] = 0x00;
}

void Remote_Rx(unsigned char *sbus_buff) 
{
    if(sbus_buff != NULL && sbus_buff[0] == 0x0F && sbus_buff[24] == 0x00)
    {
        RC_CtrlData.ch0 = (sbus_buff[1] | (sbus_buff[2] << 8)) & 0x07FF;
        RC_CtrlData.ch1 = ((sbus_buff[2] >> 3) | (sbus_buff[3] << 5)) & 0x07FF;
        RC_CtrlData.ch2 = ((sbus_buff[3] >> 6) | (sbus_buff[4] << 2) | (sbus_buff[4] << 10)) & 0x07FF;
        RC_CtrlData.ch3 = ((sbus_buff[5] >> 1) | (sbus_buff[6] << 7)) & 0x07FF;

        RC_CtrlData.s1 = (sbus_buff[6] >> 4 & 0x000C) >> 2;
        RC_CtrlData.s2 = (sbus_buff[6] >> 4 & 0x0003); 
    }
}


