#ifndef __SHOW_H
#define	__SHOW_H

#include "stm32f10x.h"
#include "bsp_led.h"

//	A-0 B-1 C-2 D-3 E-4 F-5 G-6 H-7 DP-8
//		   	A
//		F				B
//   	   	G
//		E   		C
//  	   	D    	DP
void GPIO_Tube_Config(void);		//Confige the GPIO
void GPIO_TTube_Config(void);	
void Show_Num(int num, int w); 	//only show one number
void Numlist(int *num_list,int num);	//Digital conversion
void Integer_Display(int num);			//Integer Display
void Display_HELP();			//display the word of help

											//0000 0000 HGFE DCBA        
#define TUBE0	GPIO_Write(GPIOA,0X003F);	//0000 0000 0011 1111
#define TUBE1	GPIO_Write(GPIOA,0X0006);	//0000 0000 0000 0110
#define TUBE2	GPIO_Write(GPIOA,0X005B);	//0000 0000 0101 1011
#define TUBE3	GPIO_Write(GPIOA,0X004F);	//0000 0000 0100 1111
#define TUBE4	GPIO_Write(GPIOA,0X0066);	//0000 0000 0110 0110
#define TUBE5	GPIO_Write(GPIOA,0X006D);	//0000 0000 0110 1101
#define TUBE6	GPIO_Write(GPIOA,0X007D);	//0000 0000 0111 1101
#define TUBE7	GPIO_Write(GPIOA,0X0007);	//0000 0000 0000 0111
#define TUBE8	GPIO_Write(GPIOA,0X007F);	//0000 0000 0111 1111
#define TUBE9	GPIO_Write(GPIOA,0X006F);	//0000 0000 0110 1111
#define TUBEH	GPIO_Write(GPIOA,0X0076);	//0000 0000 0111 0110
#define TUBEE	GPIO_Write(GPIOA,0X0079);	//0000 0000 0111 1001
#define TUBEL	GPIO_Write(GPIOA,0X0038);	//0000 0000 0011 1000
#define TUBEP	GPIO_Write(GPIOA,0X0073);	//0000 0000 0111 0011
#define CLEAR1 GPIO_Write(GPIOA,0X0000);	//0000 0000 0000 0000


#define TTUBE1 GPIO_Write(GPIOB,0X0E00);	//0000 1110 0000 0000
#define TTUBE2 GPIO_Write(GPIOB,0X0D00);	//0000 1101 0000 0000
#define TTUBE3 GPIO_Write(GPIOB,0X0B00);	//0000 1011 0000 0000
#define TTUBE4 GPIO_Write(GPIOB,0X0700);	//0000 0111 0000 0000
#define CLEAR2 GPIO_Write(GPIOB,0X0000);	//0000 0000 0000 0000

#endif /* __LED_H */