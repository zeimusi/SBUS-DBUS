## 注意！

如果使用了数据转换函数：

```c
void DBUS_To_SBUS(uint8_t *rc_buff ,uint8_t *sbus_buff);
```

则必须使用解码函数：

```c
void Remote_Rx(unsigned char *sbus_buff);
```

而不可用SBUS的通用解码方式进行解码。

## 关于如何发送转换后的数据

用户可自行通过串口或CAN进行发送。发送时的字节大小固定为SBUS_LEN。

