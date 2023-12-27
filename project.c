#include <reg51.h>	// Standard 8051 defines

sbit T1_R = P1^2;
sbit T1_Y = P1^1;
sbit T1_G = P1^0;

sbit T2_R = P1^5;
sbit T2_Y = P1^4;
sbit T2_G = P1^3;

sbit T3_R = P3^0;
sbit T3_Y = P1^7;
sbit T3_G = P1^6;

sbit T4_R = P3^3;
sbit T4_Y = P3^2;
sbit T4_G = P3^1;

sbit T5_R = P3^5;
sbit T5_G = P3^4;

sbit P1_R = P3^6;
sbit P1_G = P3^7;

sbit P2_R = P0^0;
sbit P2_G = P0^1;

sbit LDR = P0^2;
sbit LED = P0^3;
// Define Signal pins

// Initialize functions
void delay(unsigned int);
void streetlight();

void main()
{	
	// Initialize traffic light states
  T1_R = T2_R = T3_R = T4_R = T5_R = 0;
  T1_Y = T2_Y = T3_Y = T4_Y = 0;
  T1_G = T2_G = T3_G = T4_G = T5_G = 0;
	P1_R = P2_R = 0;
	P1_G = P2_G = 0;
  delay(100);
	T1_R = T2_R = T3_R = T4_R = T5_R = 0;
  T1_Y = T2_Y = T3_Y = T4_Y = 1;
  T1_G = T2_G = T3_G = T4_G = T5_G = 1;
	P1_R = P2_R = 1;
	P1_G = P2_G = 0;
	delay(100);
	while(1)
		{
			T1_R = T5_R = P1_G = 1;
			T1_G = T5_G = P1_R = 0;
			streetlight();
			delay(500);
			T1_G = 1;
			T1_Y = 0;
			streetlight();
			delay(300);
			T1_Y = 1;
			T5_G = P1_R = 1;
			T1_R = T5_R = P1_G = 0;
			
			T2_R = 1;
			T2_G = 0;
			streetlight();
			delay(500);
			T2_G = 1;
			T2_Y = 0;
			streetlight();
			delay(300);
			T2_Y = 1;
			T2_R = 0;
			
			T3_R = 1;
			T3_G = 0;
			streetlight();
			delay(500);
			T3_G = 1;
			T3_Y = 0;
			streetlight();
			delay(300);
			T3_Y = 1;
			T3_R = 0;
		
			T4_R = P2_G = 1;
			T4_G = P2_R = 0;
			streetlight();
			delay(500);
			T4_G = 1;
			T4_Y = 0;
			streetlight();
			delay(300);
			T4_Y = P2_R = 1;
			T4_R = P2_G = 0;
		}
}

void delay(unsigned int a)
{
	unsigned int i,j;
	for(i=0;i<a;i++)
	{
		for(j=0;j<1275;j++)
		{
			streetlight();
		}
	}
}

void streetlight()
{
	if (LDR == 0)
	{
		LED = 0;
	}
	else
	{
		LED = 1;
	}
}