#include "sys.h"
#include "usart.h"		
#include "delay.h"	
#include "show.h"
#include "oled.h"


void menu_main()//������
{
		OLED_Clear();
		OLED_ShowCHinese(0,0,0);//��ѡ��ģʽ
		OLED_ShowCHinese(16,0,1);//
		OLED_ShowCHinese(32,0,2);//
		OLED_ShowCHinese(48,0,3);//
		OLED_ShowCHinese(64,0,4);//
		OLED_ShowString(80,0,":");
		//OLED_ShowCHinese(112,0,26);//
		//OLED_ShowString(104,0,"T");
		//OLED_ShowString(112,0,"C");
		
		OLED_ShowString(0,2,"1");
		OLED_ShowString(8,2,".");	
		OLED_ShowCHinese(16,2,7);//1.��ȭģʽ
		OLED_ShowCHinese(32,2,6);//
		OLED_ShowCHinese(48,2,3);//
		OLED_ShowCHinese(64,2,4);//
		//OLED_ShowCHinese(104,2,30);//
	
	
		OLED_ShowString(0,4,"2");
		OLED_ShowString(8,4,".");	
		OLED_ShowCHinese(16,4,5);//2.��ȭģʽ
		OLED_ShowCHinese(32,4,8);//
		OLED_ShowCHinese(48,4,3);//
		OLED_ShowCHinese(64,4,4);//
		//OLED_ShowCHinese(104,4,31);//
		OLED_ShowCHinese(96,4,33);
		OLED_ShowCHinese(112,4,34);//
		
		OLED_ShowString(0,6,"3");
		OLED_ShowString(8,6,".");	
		OLED_ShowCHinese(16,6,24);//3.ѵ��ģʽ
		OLED_ShowCHinese(32,6,25);//
		OLED_ShowCHinese(48,6,3);//
		OLED_ShowCHinese(64,6,4);//
		//OLED_ShowCHinese(104,6,32);//
    //OLED_ShowString(90,6,"XUPT");  
	  //OLED_ShowString(0,6,"2020/08/05");  
		OLED_ShowCHinese(96,6,35);
		OLED_ShowCHinese(112,6,36);//

	}

void mod3_1(void)//ѵ��ģʽ
{
		OLED_Clear();
		OLED_ShowCHinese(0,0,0);//��ѡ��ѵ��ģʽ
		OLED_ShowCHinese(16,0,1);//
		OLED_ShowCHinese(32,0,2);//
		OLED_ShowCHinese(48,0,24);//
		OLED_ShowCHinese(64,0,25);//
		OLED_ShowCHinese(80,0,3);//
		OLED_ShowCHinese(96,0,4);//
		OLED_ShowString(112,0,":");
	
		OLED_ShowString(0,2,"1");
		OLED_ShowString(8,2,".");	
		OLED_ShowCHinese(16,2,5);//1.��ȭģʽ
		OLED_ShowCHinese(32,2,6);//
		OLED_ShowCHinese(48,2,3);//
		OLED_ShowCHinese(64,2,4);//
	
		OLED_ShowString(0,4,"2");
		OLED_ShowString(8,4,".");	
		OLED_ShowCHinese(16,4,7);//2.��ȭģʽ
		OLED_ShowCHinese(32,4,8);//
		OLED_ShowCHinese(48,4,3);//
		OLED_ShowCHinese(64,4,4);//
		delay_ms(1000);
}
//ѵ����
void taring_mod1(u8 x)
{
		OLED_Clear();
	if(x==0)
	{
		OLED_ShowCHinese(0,0,7);//1.��ȭģʽ
		OLED_ShowCHinese(16,0,6);//
		OLED_ShowCHinese(32,0,3);//
		OLED_ShowCHinese(48,0,4);//
		OLED_ShowCHinese(0,2,45);//����xx
		OLED_ShowCHinese(16,2,47);//
		OLED_ShowCHinese(32,2,16);//
		OLED_ShowCHinese(48,2,17);//
		OLED_ShowCHinese(0,6,24);//ѵ����
		OLED_ShowCHinese(16,6,25);//
		OLED_ShowCHinese(32,6,39);//
		OLED_ShowString(48,6,".");
		OLED_ShowString(56,6,".");
		OLED_ShowString(64,6,".");
	  delay_ms(1000);
	}
	else if(x==1)
	{
		OLED_ShowCHinese(0,0,7);//1.��ȭģʽ
		OLED_ShowCHinese(16,0,6);//
		OLED_ShowCHinese(32,0,3);//
		OLED_ShowCHinese(48,0,4);//
		OLED_ShowCHinese(0,2,45);//����xx
		OLED_ShowCHinese(16,2,47);//
		OLED_ShowCHinese(32,2,14);//
		OLED_ShowCHinese(48,2,15);//
		OLED_ShowCHinese(0,6,24);//ѵ����
		OLED_ShowCHinese(16,6,25);//
		OLED_ShowCHinese(32,6,39);//
		OLED_ShowString(48,6,".");
		OLED_ShowString(56,6,".");
		OLED_ShowString(64,6,".");
	  delay_ms(1000);
	}
	else if(x==2)
	{
		OLED_ShowCHinese(0,0,7);//1.��ȭģʽ
		OLED_ShowCHinese(16,0,6);//
		OLED_ShowCHinese(32,0,3);//
		OLED_ShowCHinese(48,0,4);//
		OLED_ShowCHinese(0,2,45);//����xx
		OLED_ShowCHinese(16,2,47);//
		OLED_ShowCHinese(32,2,18);//
		OLED_ShowCHinese(0,6,24);//ѵ����
		OLED_ShowCHinese(16,6,25);//
		OLED_ShowCHinese(32,6,39);//
		OLED_ShowString(48,6,".");
		OLED_ShowString(56,6,".");
		OLED_ShowString(64,6,".");
	  delay_ms(1000);
	}
}

void taring_mod2(u8 x)
{
	OLED_Clear();
	if(x==0)
	{
		OLED_ShowCHinese(0,0,5);//1.��ȭģʽ
		OLED_ShowCHinese(16,0,8);//
		OLED_ShowCHinese(32,0,3);//
		OLED_ShowCHinese(48,0,4);//
		OLED_ShowCHinese(0,2,45);//����xx
		OLED_ShowCHinese(16,2,47);//
		OLED_ShowCHinese(32,2,19);//
		OLED_ShowCHinese(0,6,24);//ѵ����
		OLED_ShowCHinese(16,6,25);//
		OLED_ShowCHinese(32,6,39);//
		OLED_ShowString(48,6,".");
		OLED_ShowString(56,6,".");
		OLED_ShowString(64,6,".");
	  delay_ms(1000);
	}
	else if(x==1)
	{
		OLED_ShowCHinese(0,0,5);//1.��ȭģʽ
		OLED_ShowCHinese(16,0,8);//
		OLED_ShowCHinese(32,0,3);//
		OLED_ShowCHinese(48,0,4);//
		OLED_ShowCHinese(0,2,45);//����xx
		OLED_ShowCHinese(16,2,47);//
		OLED_ShowCHinese(32,2,20);//
		OLED_ShowCHinese(0,6,24);//ѵ����
		OLED_ShowCHinese(16,6,25);//
		OLED_ShowCHinese(32,6,39);//
		OLED_ShowString(48,6,".");
		OLED_ShowString(56,6,".");
		OLED_ShowString(64,6,".");
	  delay_ms(1000);
	}
	else if(x==2)
	{
		OLED_ShowCHinese(0,0,5);//1.��ȭģʽ
		OLED_ShowCHinese(16,0,8);//
		OLED_ShowCHinese(32,0,3);//
		OLED_ShowCHinese(48,0,4);//
		OLED_ShowCHinese(0,2,45);//����xx
		OLED_ShowCHinese(16,2,47);//
		OLED_ShowCHinese(32,2,21);//
		OLED_ShowCHinese(0,6,24);//ѵ����
		OLED_ShowCHinese(16,6,25);//
		OLED_ShowCHinese(32,6,39);//
		OLED_ShowString(48,6,".");
		OLED_ShowString(56,6,".");
		OLED_ShowString(64,6,".");
	  delay_ms(1000);
	}
	else if(x==3)
	{
		OLED_ShowCHinese(0,0,5);//1.��ȭģʽ
		OLED_ShowCHinese(16,0,8);//
		OLED_ShowCHinese(32,0,3);//
		OLED_ShowCHinese(48,0,4);//
		OLED_ShowCHinese(0,2,45);//����xx
		OLED_ShowCHinese(16,2,47);//
		OLED_ShowCHinese(32,2,22);//
		OLED_ShowCHinese(0,6,24);//ѵ����
		OLED_ShowCHinese(16,6,25);//
		OLED_ShowCHinese(32,6,39);//
		OLED_ShowString(48,6,".");
		OLED_ShowString(56,6,".");
		OLED_ShowString(64,6,".");
	  delay_ms(1000);
	}
	else if(x==4)
	{
		OLED_ShowCHinese(0,0,5);//1.��ȭģʽ
		OLED_ShowCHinese(16,0,8);//
		OLED_ShowCHinese(32,0,3);//
		OLED_ShowCHinese(48,0,4);//
		OLED_ShowCHinese(0,2,45);//����xx
		OLED_ShowCHinese(16,2,47);//
		OLED_ShowCHinese(32,2,23);//
		OLED_ShowCHinese(0,6,24);//ѵ����
		OLED_ShowCHinese(16,6,25);//
		OLED_ShowCHinese(32,6,39);//
		OLED_ShowString(48,6,".");
		OLED_ShowString(56,6,".");
		OLED_ShowString(64,6,".");
	}
}

//����
void fix_up()
{
		OLED_Clear();
		OLED_ShowCHinese(0,0,0);//��ѡ����ȷģʽ
		OLED_ShowCHinese(16,0,1);//
		OLED_ShowCHinese(32,0,2);//
		OLED_ShowCHinese(48,0,40);//
		OLED_ShowCHinese(64,0,41);//
		OLED_ShowCHinese(80,0,42);//
		OLED_ShowCHinese(96,0,3);//
		OLED_ShowCHinese(112,0,4);//
	  delay_ms(1000);
}	

//������
void mod_1_testing(void)
{
		OLED_Clear();
		OLED_ShowString(0,0,"1");
		OLED_ShowString(8,0,".");	
		OLED_ShowCHinese(16,0,7);//1.��ȭģʽ
		OLED_ShowCHinese(32,0,6);//
		OLED_ShowCHinese(48,0,3);//
		OLED_ShowCHinese(64,0,4);//
		OLED_ShowCHinese(0,2,0);//���������
		OLED_ShowCHinese(16,2,43);//
		OLED_ShowCHinese(32,2,44);//
		OLED_ShowCHinese(48,2,45);//
		OLED_ShowCHinese(64,2,46);//
	  delay_ms(1000);
}

void mod_2_testing(void)
{
		OLED_Clear();
		OLED_ShowString(0,0,"2");
		OLED_ShowString(8,0,".");	
		OLED_ShowCHinese(16,0,5);//1.��ȭģʽ
		OLED_ShowCHinese(32,0,6);//
		OLED_ShowCHinese(48,0,3);//
		OLED_ShowCHinese(64,0,4);//
		OLED_ShowCHinese(0,2,0);//���������
		OLED_ShowCHinese(16,2,43);//
		OLED_ShowCHinese(32,2,44);//
		OLED_ShowCHinese(48,2,45);//
		OLED_ShowCHinese(64,2,46);//
	  delay_ms(1000);
}

//��ȭ
void mod1_0()
{
		OLED_Clear();
		OLED_ShowString(0,0,"2");
		OLED_ShowString(8,0,".");	
		OLED_ShowCHinese(16,0,5);//1.��ȭģʽ
		OLED_ShowCHinese(32,0,6);//
		OLED_ShowCHinese(48,0,3);//
		OLED_ShowCHinese(64,0,4);//
		OLED_ShowCHinese(0,2,9);//ʶ����Ϊ
		OLED_ShowCHinese(16,2,10);//
		OLED_ShowCHinese(32,2,11);//
		OLED_ShowCHinese(48,2,12);//
		OLED_ShowCHinese(64,2,13);//
		OLED_ShowString(80,2,":");

		OLED_ShowCHinese(48,5,16);//ʯͷ
		OLED_ShowCHinese(64,5,17);//
	delay_ms(1000);

}
void mod1_2()
{
		OLED_Clear();
		OLED_ShowString(0,0,"2");
		OLED_ShowString(8,0,".");	
		OLED_ShowCHinese(16,0,7);//2.��ȭģʽ
		OLED_ShowCHinese(32,0,8);//
		OLED_ShowCHinese(48,0,3);//
		OLED_ShowCHinese(64,0,4);//
		OLED_ShowCHinese(0,2,9);//ʶ����Ϊ
		OLED_ShowCHinese(16,2,10);//
		OLED_ShowCHinese(32,2,11);//
		OLED_ShowCHinese(48,2,12);//
		OLED_ShowCHinese(64,2,13);//
		OLED_ShowString(80,2,":");
		OLED_ShowCHinese(48,5,14);//����
		OLED_ShowCHinese(64,5,15);//
	delay_ms(1000);
}
void mod1_5()
{
		OLED_Clear();
		OLED_ShowString(0,0,"2");
		OLED_ShowString(8,0,".");	
		OLED_ShowCHinese(16,0,5);//1.��ȭģʽ
		OLED_ShowCHinese(32,0,6);//
		OLED_ShowCHinese(48,0,3);//
		OLED_ShowCHinese(64,0,4);//
		OLED_ShowCHinese(0,2,9);//ʶ����Ϊ
		OLED_ShowCHinese(16,2,10);//
		OLED_ShowCHinese(32,2,11);//
		OLED_ShowCHinese(48,2,12);//
		OLED_ShowCHinese(64,2,13);//
		OLED_ShowString(80,2,":");
		OLED_ShowCHinese(54,5,18);//��
	delay_ms(1000);
}
//��ȭ
void mod2_1()
{
		OLED_Clear();
		OLED_ShowString(0,0,"1");
		OLED_ShowString(8,0,".");	
		OLED_ShowCHinese(16,0,7);//2.��ȭģʽ
		OLED_ShowCHinese(32,0,8);//
		OLED_ShowCHinese(48,0,3);//
		OLED_ShowCHinese(64,0,4);//
		OLED_ShowCHinese(0,2,9);//ʶ����Ϊ
		OLED_ShowCHinese(16,2,10);//
		OLED_ShowCHinese(32,2,11);//
		OLED_ShowCHinese(48,2,12);//
		OLED_ShowCHinese(64,2,13);//
		OLED_ShowString(80,2,":");
		OLED_ShowCHinese(54,5,19);//1
	delay_ms(1000);
}
void mod2_2()
{
		OLED_Clear();
		OLED_Clear();
		OLED_ShowString(0,0,"1");
		OLED_ShowString(8,0,".");	
		OLED_ShowCHinese(16,0,7);//2.��ȭģʽ
		OLED_ShowCHinese(32,0,8);//
		OLED_ShowCHinese(48,0,3);//
		OLED_ShowCHinese(64,0,4);//
		OLED_ShowCHinese(0,2,9);//ʶ����Ϊ
		OLED_ShowCHinese(16,2,10);//
		OLED_ShowCHinese(32,2,11);//
		OLED_ShowCHinese(48,2,12);//
		OLED_ShowCHinese(64,2,13);//
		OLED_ShowString(80,2,":");
		OLED_ShowCHinese(54,5,20);//2
	delay_ms(1000);
}
void mod2_3()
{
		OLED_Clear();
		OLED_ShowString(0,0,"1");
		OLED_ShowString(8,0,".");	
		OLED_ShowCHinese(16,0,7);//2.��ȭģʽ
		OLED_ShowCHinese(32,0,8);//
		OLED_ShowCHinese(48,0,3);//
		OLED_ShowCHinese(64,0,4);//
		OLED_ShowCHinese(0,2,9);//ʶ����Ϊ
		OLED_ShowCHinese(16,2,10);//
		OLED_ShowCHinese(32,2,11);//
		OLED_ShowCHinese(48,2,12);//
		OLED_ShowCHinese(64,2,13);//
		OLED_ShowString(80,2,":");
		OLED_ShowCHinese(54,5,21);//3
	delay_ms(1000);
}
void mod2_4()
{
		OLED_Clear();
		OLED_ShowString(0,0,"1");
		OLED_ShowString(8,0,".");	
		OLED_ShowCHinese(16,0,7);//2.��ȭģʽ
		OLED_ShowCHinese(32,0,8);//
		OLED_ShowCHinese(48,0,3);//
		OLED_ShowCHinese(64,0,4);//
		OLED_ShowCHinese(0,2,9);//ʶ����Ϊ
		OLED_ShowCHinese(16,2,10);//
		OLED_ShowCHinese(32,2,11);//
		OLED_ShowCHinese(48,2,12);//
		OLED_ShowCHinese(64,2,13);//
		OLED_ShowString(80,2,":");
		OLED_ShowCHinese(54,5,22);//4
	delay_ms(1000);
}
void mod2_5()
{
		OLED_Clear();
		OLED_ShowString(0,0,"1");
		OLED_ShowString(8,0,".");	
		OLED_ShowCHinese(16,0,7);//2.��ȭģʽ
		OLED_ShowCHinese(32,0,8);//
		OLED_ShowCHinese(48,0,3);//
		OLED_ShowCHinese(64,0,4);//
		OLED_ShowCHinese(0,2,9);//ʶ����Ϊ
		OLED_ShowCHinese(16,2,10);//
		OLED_ShowCHinese(32,2,11);//
		OLED_ShowCHinese(48,2,12);//
		OLED_ShowCHinese(64,2,13);//
		OLED_ShowString(80,2,":");
		OLED_ShowCHinese(54,5,23);//5
	delay_ms(1000);
}	

