#include "led.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "oled.h"
#include "FDC2214.h"
#include "timer.h"
#include "control.h"
#include "show.h"

void FDC2214_GetData(void);
u32 ch0,ch1,ch2,ch3;
double fre=0,cap3_first=0;
int main(void)
{ 
	Stm32_Clock_Init(9); 	//ϵͳʱ������78
	delay_init();//��ʱ������ʼ��	
  uart_init(72,921600);//���ڳ�ʼ��   789
  TIM1_36Mhz_Init();//stm32��ʱ��1���һ��36mhz��������Ϊfdc2214��ʱ�ӡ����������40mhz�ľ�������Ͳ���Ҫ�ˡ�
  OLED_Init();
  IIC_Init();
  FDC2214_Init(); 
//	KEY_Init();
	OLED_Clear();
	delay_ms(100);
	FDC2214_GetChannelData(FDC2214_Channel_3, &ch3);
	cap3_first=FDC2214_getcap(ch3);//����ʼֵ
	printf("cap3_first=%f \r\n",cap3_first);
	while(1)
	{
		FDC2214_GetChannelData(FDC2214_Channel_3, &ch3);
		CPChannel_Control();
//	 FDC2214_GetData();
// //       printf("\r\nCH0~3(%d , %d , %d , %d)",ch0,ch1,ch2,ch3);
//		printf("CH3:	%d	",ch3);
////		 fre=FDC2214_CalculateFrequency(FDC2214_Channel_3,ch3);
////		printf("fre:	%f	",fre);
//	   cap_old=232021045.248/(ch3);
//	   cap_new=cap_old*cap_old;
//		printf("cap:	%f \r\n",cap_new);
//	 				if( ch3>39074313 )
//						printf("û���֡\\r\n");
//					else
//						printf("��!\r\n");
//	  	OLED_ShowString(0,1,"cap:");
//		  OLED_ShowNum(50,1,cap_new,4,12);      //��ʾ��������	   		
			delay_ms(500);	 //��ʱ300ms
	}
 }
void FDC2214_GetData(void)
{
    FDC2214_GetChannelData(FDC2214_Channel_0, &ch0);  
    FDC2214_GetChannelData(FDC2214_Channel_1, &ch1);
    FDC2214_GetChannelData(FDC2214_Channel_2, &ch2);
    FDC2214_GetChannelData(FDC2214_Channel_3, &ch3);
}
