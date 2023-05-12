#include<reg51.h>
sbit sensor=P1^0;
sbit rs=P1^1;
sbit rw=P1^2;
sbit en=P1^3;
sbit buzzer=P3^3;
void lcdint();
void lcddat(unsigned char);
void lcdcmd(unsigned char);
void lcddis(unsigned char*);
void delay();
void main()
{
buzzer=0;
sensor=0;
back:lcdint();
lcddis(" FIRE ALERT ");
lcdcmd(0xc0);
lcddis(" SYSTEM ");
delay();
while(1)
{
if(sensor==1)
    {lcdcmd(0x01);
	lcddis("FIRE OCCURED");
	buzzer=1;
	}
goto back;
}
}
void lcddat(unsigned char dat)
    {
    P2=dat;
	rs=1;
	rw=0;
	en=1;
	delay();
	en=0;
	}
void lcddis(unsigned char*s)
    {
	unsigned char w;
	for(w=0;s[w]!='\0';w++)
	    {
		lcddat(s[w]);
		}
	}
void delay()
    {
	  unsigned int v1;
	  for(v1=0;v1<1000;v1++);
	  }
