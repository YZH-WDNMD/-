#include "key.h"
#include "delay.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK Mini STM32������
//�������� ��������		   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2014/3/06
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2009-2019
//All rights reserved									   
//////////////////////////////////////////////////////////////////////////////////	 
 	    
//������ʼ������ 
//PA15��PC5 ���ó�����
void KEY_Init(void)
{
	
	GPIO_InitTypeDef GPIO_InitStructure;

 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//ʹ��PORTBʱ��

	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);//�ر�jtag��ʹ��SWD��������SWDģʽ����
	
//	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_9;//PB1
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //���ó���������
// 	GPIO_Init(GPIOB, &GPIO_InitStructure);//��ʼ��GPIOB1
//	
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_6;//PB6
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //���ó���������
 	GPIO_Init(GPIOB, &GPIO_InitStructure);//��ʼ��GPIOB6
	
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_7;//PB7
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //���ó���������
 	GPIO_Init(GPIOB, &GPIO_InitStructure);//��ʼ��GPIOB7
 
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_8;//PB8
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //PA0���ó����룬Ĭ������	  
	GPIO_Init(GPIOB, &GPIO_InitStructure);//��ʼ��GPIOB8
	
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0;//PC5
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //���ó���������
 	GPIO_Init(GPIOA, &GPIO_InitStructure);//��ʼ��GPIOC5
	
} 

//void KEY_Init(void)
//{
//		RCC->APB2ENR|=1<<3;     //ʹ��PORTBʱ��
////	//RCC->APB2ENR|=1<<4;     //ʹ��PORTCʱ��
////	JTAG_Set(SWD_ENABLE);	//�ر�JTAG,����SWD
//	GPIOB->CRL&=0X00FFFF0F;	//PB67���ó�����	  
//	GPIOB->CRL|=0X88000080;   
//	GPIOB->CRH&=0XFFFFFFF0;	//PB8���ó�����	  
//	GPIOB->CRH|=0X000000F8;   
////	//GPIOA->CRH&=0X0FFFFFFF;	//PA15���ó�����	  
////	//GPIOA->CRH|=0X80000000; 			 
//	GPIOB->ODR|=1<<6;	   	//PA15����,PA0Ĭ������
////	//GPIOC->CRL&=0XFF0FFFFF;	//PC5���ó�����	  
////	//GPIOC->CRL|=0X00800000;   
//	GPIOB->ODR|=1<<7;	   	//PC5����
//  GPIOB->ODR|=1<<1;	   	//PC5���� 	
//	GPIOB->ODR|=1<<8;	   	//PC5����
//} 

//����������
//���ذ���ֵ
//mode:0,��֧��������;1,֧��������;
//����ֵ��
//0��û���κΰ�������
//KEY0_PRES��KEY0����
//KEY1_PRES��KEY1����
//WKUP_PRES��WK_UP���� 
//ע��˺�������Ӧ���ȼ�,KEY0>KEY1>WK_UP!!

//u8 KEY_Scan(u8 mode)
//{	 
//	static u8 key_up=1;//�������ɿ���־
//	if(mode)key_up=1;  //֧������		  
//	if(key_up&&KEY3==0)
//	{
//		delay_ms(10);//ȥ���� 
//		key_up=0;
//		if(KEY3==0)return KEY3_PRES;
//	}else if(KEY3==1)key_up=1; 	     
//	return 0;// �ް�������
//}



