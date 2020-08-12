#include "control.h"
#include "exti.h"
#include "filter.h"
#include "key.h"
#include "sys.h"
#include "fdc2214.h"
#include "show.h"
//static u8 KEY2_Flag=0;
//static u8 KEY1_Flag=0;
//static u8 KEY0_Flag=0; 
u8 KEY2_Flag;
u8 KEY1_Flag;
u8 KEY0_Flag; 
double cap3_mid,cap3_last,cap3_mid1;
double train_C[3][100],trainC[3]={0};
double train_H[5][100],trainH[5]={0};
u8 init;
/*
void PID(double x)
{
		double kp=10;
		x=0;
		cap3_first=kp*x;
		cap3_mid=cap3_last-cap3_first;
//		return cap3_mid;
}
*/
//void Keyscan()
//{
//	u8 t=0;	  
//	t=KEY_Scan(0);		//�õ���ֵ
//		switch(t)
//		{				 
//			case KEY0_PRES:
//				KEY0_Flag=1;
//				break;
//			case KEY1_PRES:
//				KEY1_Flag=1;
//				break;
//			case KEY2_PRES:				
//				KEY2_Flag=1;
//				break;
//			default:
//				delay_ms(10);
//        break;			
//			
//		} 
//}
void CPChannel_Control()
{
	u8 key;	

//	Keyscan();
//	delay_ms(10);
//	KEY0_Flag=KEY0_Scan(0);  	//����ɨ�躯��	
//	delay_ms(50);
//	KEY1_Flag=KEY1_Scan(0);
//	delay_ms(50);
//	KEY2_Flag=KEY2_Scan(0);
//	delay_ms(50);
		
		
		KEY2_Flag=key2;
		KEY1_Flag=key1*10;
		KEY0_Flag=key0*100;  	//����ɨ�躯��	
	  key=KEY0_Flag+KEY1_Flag+KEY2_Flag;
		delay_ms(10);
	switch(key)
	{
		case 0:
			 printf("������\r\n");
		   menu_main();
			 printf("KEY0_Flag,KEY1_Flag,KEY2_Flag,key:%d,%d,%d,%d\r\n",KEY0_Flag,KEY1_Flag,KEY2_Flag,key);
		   //delay_ms(200);
		   break;
		case 1:
			 printf("��ѡ��¼��ģʽ\r\n");
		   mod3_1();	   
			 printf("KEY0_Flag,KEY1_Flag,KEY2_Flag,key:%d,%d,%d,%d\r\n",KEY0_Flag,KEY1_Flag,KEY2_Flag,key);
		   delay_ms(100);
		   break;
		case 10:
			 printf("��ȭ\r\n");
	     Caiquan();
			 printf("KEY0_Flag,KEY1_Flag,KEY2_Flag,key:%d,%d,%d,%d\r\n",KEY0_Flag,KEY1_Flag,KEY2_Flag,key);
			 printf("cap3_mid:%f\r\n",cap3_mid);
		   delay_ms(200);
		   break;
		case 11:
			 printf("��ȭ¼��\r\n");
		   //taring_mod1();
		//printf("KEY0_Flag,KEY1_Flag,KEY2_Flag,key:%d,%d,%d,%d\r\n",KEY0_Flag,KEY1_Flag,KEY2_Flag,key);
		   CqTrain();
		//   Zero();
		   delay_ms(100);
		   break;
		case 100:
			 printf("��ȭ\r\n");		   
		   Huaquan();
			 printf("KEY0_Flag,KEY1_Flag,KEY2_Flag,key:%d,%d,%d,%d\r\n",KEY0_Flag,KEY1_Flag,KEY2_Flag,key);
			 printf("cap3_mid:%f\r\n",cap3_mid);
		   delay_ms(200);
		   break;
		case 101:
			 printf("��ȭ¼��\r\n");
		   //taring_mod2();
		   HqTrain();
//		//   Zero();
			 printf("KEY0_Flag,KEY1_Flag,KEY2_Flag,key:%d,%d,%d,%d\r\n",KEY0_Flag,KEY1_Flag,KEY2_Flag,key);
		   delay_ms(100);
		   break;
		default:
			 fix_up();
		   //menu_main();
			 printf("KEY0_Flag,KEY1_Flag,KEY2_Flag,key:%d,%d,%d,%d\r\n",KEY0_Flag,KEY1_Flag,KEY2_Flag,key);
			 delay_ms(100);
		   break;
	}
}

void Caiquan()
{
  cap3_last=FDC2214_getcap(ch3);//�ɼ�����
	cap3_mid=cap3_last-cap3_first;//���ݽӿڿ��ؼ�����ʼֵ
//	PID(cap3_mid1);
	if(cap3_mid> (60.0+init) && cap3_mid< (75.0+init) )
	{
		delay_ms(100);
		printf("ʯͷ\r\n");
		mod1_0();
	}
	else if(cap3_mid>(45.0+init)&&cap3_mid< (60.0+init) )
	{
		delay_ms(100);
		printf("����\r\n");
		mod1_2();
	}
	else if(cap3_mid> (75.0+init))
	{
		delay_ms(100);
		printf("��\r\n");
		mod1_5();
	}
	else if(cap3_mid<45)
	{
		delay_ms(100);
		printf("��������\r\n");
		init=cap3_mid;
		mod_2_testing();
	}
}
void Huaquan()
{
	cap3_last=FDC2214_getcap(ch3);//�ɼ�����
	cap3_mid=cap3_last-cap3_first;//���ݽӿڿ��ؼ�����ʼֵ
//	PID(cap3_mid1);
	if(cap3_mid> (40.0+init) && cap3_mid< (56.0+init) )
	{
		delay_ms(100);
		printf("11111\r\n");
		mod2_1();
	}
	else if(cap3_mid< (58.0+init) && cap3_mid >(52.0+init))
	{
		delay_ms(100);
		printf("22222\r\n");
		mod2_2();
	}
	else if(cap3_mid>(58.0+init) && cap3_mid< (65.0+init) )
	{
		delay_ms(100);
		printf("33333\r\n");
		mod2_3();
	}
	else if(cap3_mid>(65.0+init) && cap3_mid< (75.0+init) )
	{
		delay_ms(100);
		printf("44444\r\n");
		mod2_4();
	}
	else if(cap3_mid> (75.0+init))
	{
		delay_ms(100);
		printf("55555\r\n");
		mod2_5();
	}
	else if(cap3_mid<(40+init))
	{
		delay_ms(100);
		printf("��������\r\n");
		init=cap3_mid;
		mod_1_testing();
	}
}
//void CqTrain()  //��ȭѵ��
//{
//	u8 i;
//	cap3_last=FDC2214_getcap(ch3);//�ɼ�����
//	cap3_mid=cap3_last-cap3_first;//���ݽӿڿ��ؼ�����ʼֵ
////	PID(cap3_mid1);
//	delay_ms(10);
//	for(i=0;i<3;i++)
//	{
//		delay_ms(100);
//		train_C[i]=cap3_mid;
//		cap3_last=FDC2214_getcap(ch3);//�ɼ�����
//  	cap3_mid=cap3_last-cap3_first;//���ݽӿڿ��ؼ�����ʼֵ
////	  PID(cap3_mid1);
//		delay_ms(10);
//	}
//	cap3_last=FDC2214_getcap(ch3);//�ɼ�����
//  cap3_mid=cap3_last-cap3_first;//���ݽӿڿ��ؼ�����ʼֵ
////	PID(cap3_mid1);
//	if(cap3_mid>train_C[0]-10 && cap3_mid>train_C[0]+10)
//	{
//		delay_ms(100);
//		printf("ʯͷ\r\n");
//		mod1_0();
//	}
//	if(cap3_mid>train_C[1]-10 && cap3_mid>train_C[1]+10)
//	{
//		delay_ms(100);
//		printf("����\r\n");
//		mod1_2();
//	}
//	if(cap3_mid>train_C[2]-10 && cap3_mid>train_C[2]+10)
//	{
//		delay_ms(100);
//		printf("��\r\n");
//		mod1_5();
//	}
//}
//void HqTrain()  //��ȭѵ��
//{
//	u8 j;
////	cap3_last=FDC2214_getcap(ch3);//�ɼ�����
////	cap3_mid=cap3_last-cap3_first;//���ݽӿڿ��ؼ�����ʼֵ
////	PID(cap3_mid1);
//	for(j=0;j<5;j++)
//	{
//		cap3_last=FDC2214_getcap(ch3);//�ɼ�����
//  	cap3_mid=cap3_last-cap3_first;//���ݽӿڿ��ؼ�����ʼֵ
//		train_H[j]=(int)cap3_mid;
//		delay_ms(1000);
//		printf("oooooook\r\n");
////	  PID(cap3_mid1);
//	}
//	
//	for(j=0;j<5;j++)
//	{
//		printf("%d:%d\r\n",j,train_H[j]);
////	  PID(cap3_mid1);
//	}
//	
//	printf("¼�����\r\n");
//	delay_ms(1000);
//	cap3_last=FDC2214_getcap(ch3);//�ɼ�����
//  cap3_mid=cap3_last-cap3_first;//���ݽӿڿ��ؼ�����ʼֵ
////	PID(cap3_mid1);
//	if(cap3_mid>train_H[0]-10 && cap3_mid<train_H[0]+10)
//	{
//		delay_ms(100);
//		printf("1111111\r\n");
//		mod2_1();
//	}
//	else if(cap3_mid>train_H[1]-10 && cap3_mid<train_H[1]+10)
//	{
//		delay_ms(100);
//		printf("2222222\r\n");
//		mod2_2();
//	}
//	else if(cap3_mid>train_H[2]-10 && cap3_mid<train_H[2]+10)
//	{
//		delay_ms(100);
//		printf("3333333\r\n");
//		mod2_3();
//	}
//	else if(cap3_mid>train_H[3]-10 && cap3_mid<train_H[3]+10)
//	{
//		delay_ms(100);
//		printf("4444444\r\n");
//		mod2_4();
//	}
//	else if(cap3_mid>train_H[4]-10 && cap3_mid<train_H[4]+10)
//	{
//		delay_ms(100);
//		printf("5555555\r\n");
//		mod2_5();
//	}
//	
/*
	for(i ���ѭ����Ӧ1-5)
	{
		//if(i==xx)
		���棺��¼��xx����
		for(j ����ѭ����Ӧÿ�����Ƶ�ѵ������)
		{
			printf("����i�ĵ�j��¼��");
			while(1)
			{
				if(��������)
					��������
					break��
				else
					����ѭ��
			}
		}
	}
	
	
	while(1)
	{
		¼����ɣ�����ʶ��
		if(��ť����)
		{
				�����ж�
				������
				delay��
				break��
		}
		else
		���棺¼����ɣ����°�������
	}
	

	
	
	
*/	
void CqTrain()  //��ȭѵ��	----------------------------------------------------------------------------------------------------
{
	u8 i,j,t=0;
//	printf("%d\r\n",ch3);
//	cap3_last=FDC2214_getcap(ch3);//�ɼ�����
//	cap3_mid=cap3_last-cap3_first;//���ݽӿڿ��ؼ�����ʼֵ
	for(i=0;i<3;i++)
	{
		delay_ms(100);
		taring_mod1(i);
		for(j=0;j<3;j++)
		{
				printf("\r\n����%d�ĵ�%d��¼�� \r\n",i+1,j+1);
			  while(1)
				{
			   if(key3==0)
				 {
//					 cap3_last=FDC2214_getcap(ch3);//�ɼ�����
//	         cap3_mid=cap3_last-cap3_first;
					 FDC2214_GetChannelData(FDC2214_Channel_3, &ch3);
					 cap3_last=FDC2214_getcap(ch3);//�ɼ�����
					 cap3_mid=cap3_last-cap3_first;//���ݽӿڿ��ؼ�����ʼֵ
					 train_C[i][j]=cap3_mid;
					 printf("%ftrainC\r\n",cap3_mid);
				   delay_ms(1000);
					 delay_ms(1000);
					 //key3=1;
					 break;
				 }
				 else
				 {
					 printf("trainC:%f\r\n",cap3_mid);
					 delay_ms(100);
				 }
				}		
		}
	}
	delay_ms(500);
	for(i=0;i<3;i++)
	{
		trainC[i]=(train_C[i][0]+train_C[i][1]+train_C[i][2])/3;
		printf("trainC[%d]��%f\r\n",i,trainC[i]);
	}
	while(1)
	{
		delay_ms(10);
		//չʾ����
		//�ж�
			FDC2214_GetChannelData(FDC2214_Channel_3, &ch3);
			cap3_last=FDC2214_getcap(ch3);//�ɼ�����
			cap3_mid=cap3_last-cap3_first;//���ݽӿڿ��ؼ�����ʼֵ
			if(cap3_mid>trainC[0]-5 && cap3_mid<trainC[0]+3)
		{
			delay_ms(100);
			printf("ʯͷ\r\n");
			mod1_0();
		}
		if(cap3_mid>trainC[1]-5 && cap3_mid<trainC[1]+3)
		{
			delay_ms(100);
			printf("����\r\n");
			mod1_2();
		}
		if(cap3_mid>trainC[2]-3 && cap3_mid<trainC[2]+5)
		{
			delay_ms(100);
			printf("��\r\n");
			mod1_5();
		}

		if(cap3_mid>trainC[2]+10)
		{
			break;
		}
//		
	}
	
}	
void HqTrain()  //��ȭѵ��	----------------------------------------------------------------------------------------------------
{
	u8 i,j,t=0;
//	printf("%d\r\n",ch3);
//	cap3_last=FDC2214_getcap(ch3);//�ɼ�����
//	cap3_mid=cap3_last-cap3_first;//���ݽӿڿ��ؼ�����ʼֵ
	for(i=0;i<5;i++)
	{
		delay_ms(100);
		taring_mod2(i);
		for(j=0;j<3;j++)
		{
				printf("\r\n����%d�ĵ�%d��¼�� \r\n",i+1,j+1);
			  while(1)
				{
			   if(key3==0)
				 {
//					 cap3_last=FDC2214_getcap(ch3);//�ɼ�����
//	         cap3_mid=cap3_last-cap3_first;
					 FDC2214_GetChannelData(FDC2214_Channel_3, &ch3);
					 cap3_last=FDC2214_getcap(ch3);//�ɼ�����
					 cap3_mid=cap3_last-cap3_first;//���ݽӿڿ��ؼ�����ʼֵ
					 train_H[i][j]=cap3_mid;
					 printf("%ftrainC\r\n",cap3_mid);
				   delay_ms(1000);
					 delay_ms(1000);
					 //key3=1;
					 break;
				 }
				 else
				 {
					 printf("trainC:%f\r\n",cap3_mid);
					 delay_ms(100);
				 }
				}		
		}
	}
	delay_ms(500);
	for(i=0;i<5;i++)
	{
		trainH[i]=(train_H[i][0]+train_H[i][1]+train_H[i][2])/3;
		printf("trainH[%d]��%f\r\n",i,trainH[i]);
	}
	while(1)
	{
		delay_ms(10);
		//չʾ����
		//�ж�
			FDC2214_GetChannelData(FDC2214_Channel_3, &ch3);
			cap3_last=FDC2214_getcap(ch3);//�ɼ�����
			cap3_mid=cap3_last-cap3_first;//���ݽӿڿ��ؼ�����ʼֵ
			if(cap3_mid>trainH[0]-10 && cap3_mid<trainH[0]+10)
	{
		delay_ms(100);
		printf("1111111\r\n");
		mod2_1();
	}
	else if(cap3_mid>trainH[1]-2 && cap3_mid<trainH[1]+2)
	{
		delay_ms(100);
		printf("2222222\r\n");
		mod2_2();
	}
	else if(cap3_mid>trainH[2]-2 && cap3_mid<trainH[2]+2)
	{
		delay_ms(100);
		printf("3333333\r\n");
		mod2_3();
	}
	else if(cap3_mid>trainH[3]-2 && cap3_mid<trainH[3]+2)
	{
		delay_ms(100);
		printf("4444444\r\n");
		mod2_4();
	}
	else if(cap3_mid>trainH[4]-2 && cap3_mid<trainH[4]+2)
	{
		delay_ms(100);
		printf("5555555\r\n");
		mod2_5();
	}

		if(cap3_mid>trainH[4]+10)
		{
			break;
		}
//		
	}
	
}	
//--------------------------------------------------------------------------
//}
//void Zero(void)
//{
//	u8 m,n;
//	for(m=0;m<3;m++)
//	{
//		train_C[m]=0;
//	}
//	for(n=0;n<5;n++)
//	{
//		train_H[n]=0;
//	}
//}

