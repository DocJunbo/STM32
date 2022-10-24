#include "Show.h"  

void GPIO_Tube_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);//ʹ��RCC����GPIOʱ��
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //�������
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All;//��16���˿�ȫ������Ϊ������� 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
}

void GPIO_TTube_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);//ʹ��RCC����GPIOʱ��
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //�������
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3; 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
}

void Show_Num(int num, int w)		
{
	switch(num)
	{
		case 0:
			TUBE0;
			break;
		case 1:
			TUBE1;
			break;
		case 2:
			TUBE2;
			break;
		case 3:
			TUBE3;
			break;
		case 4:
			TUBE4;
			break;
		case 5:
			TUBE5;
			break;
		case 6:
			TUBE6;
			break;
		case 7:
			TUBE7;
			break;
		case 8:
			TUBE8;
			break;	
		case 9:
			TUBE9;
			break;	
		case 10:
			CLEAR1;
			break;
		default:
			break;
	}
	switch(w)
	{
		case 1:
			TTUBE1;
			break;
		case 2:
			TTUBE2;
			break;
		case 3:
			TTUBE3;
			break;
		case 4:
			TTUBE4;
			break;		
		default:
			break;
	}
}

void Numlist(int *num_list,int num)
{
	/*
		num : input the 4 numbers(1378)
		*num_list :  store the 4 numbers in array[1,3,7,8]
	*/
	int i,temp = 0;
	for(i = 0; i < 4; i++)
	{
		temp = num%10;
		num = num/10;
		num_list[4-i-1] = temp;
	}
}

void Integer_Display(int num)
{
	int temp;
	int nnum[4];
	if (num > 999)
	{
		for (int i = 0; i < 4; i++)
		{
			temp = num % 10;
			num = num / 10;
			nnum[4-i-1] = temp;
		}
	}
	else if (num <= 999 && num > 99)
	{
		for (int i = 0; i < 3; i++)
		{
			temp = num % 10;
			num = num / 10;
			nnum[4-i-1] = temp;
		}
		nnum[0] = 10;
	}
	else if (num <= 99 && num > 9)
	{
		for (int i = 0; i < 2; i++)
		{
			temp = num % 10;
			num = num / 10;
			nnum[4-i-1] = temp;
		}
		nnum[0] = nnum[1] = 10;
	}
	else
	{
		nnum[4-1] = num;
		nnum[0] = nnum[1] = nnum[2] = 10;
	}
	
	int j,t;
	// for(t=0;t<100000;t++)
	// {
		for(j = 0; j < 4; j++)
		{
			Show_Num(nnum[4-j-1],4-j);
			SOFT_DELAY;
			CLEAR1;CLEAR2;
		}
	// }	
}

void Display()	
{
	int i,t;
	for(t=0;t<100000;t++)
	{
		for(i=0;i<4;i++)
		{
			Show_Num(i+1,i+1);
			SOFT_DELAY;
			CLEAR1;CLEAR2;
		}
	}
}
