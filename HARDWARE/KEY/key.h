#ifndef __KEY_H
#define __KEY_H	 
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK miniSTM32������
//������������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2012/9/3
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2009-2019
//All rights reserved									  
//////////////////////////////////////////////////////////////////////////////////   	 


//#define KEY0 PCin(5)   	
//#define KEY1 PAin(15)	 
//#define WK_UP  PAin(0)	 
 

//#define KEY0  GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_6)//��ȡ����0
//#define KEY1  GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_7)//��ȡ����1
////#define KEY2  GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_8)//��ȡ����2 
//#define KEY3  GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_9)//��ȡ����3
#define KEY3 GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)//��ȡ����3

#define KEY0_PRES	100		//KEY0  
#define KEY1_PRES	10		//KEY1 
#define KEY2_PRES	1		//WK_UP 
#define KEY3_PRES	1		//key3


#define key0 PBin(6)
#define key1 PBin(7)
#define key2 PBin(8)
#define key3 PAin(0)

void KEY_Init(void);//IO��ʼ��
//u8 KEY0_Scan(u8 mode);  	//����ɨ�躯��	
//u8 KEY1_Scan(u8 mode);
//u8 KEY2_Scan(u8 mode);
//u8 KEY_Scan(u8 mode);
#endif
