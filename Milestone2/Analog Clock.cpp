#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<ctime>
#include<math.h>
#define PI 3.14
main()
{
	initwindow(1000,700,"ANALOG CLOCK");
	char *a[13]={"","1","2","3","4","5","6","7","8","9","10","11","12"};

		time_t rawtime;
	
	struct tm* currenttime;
		
	
	while(1)
	{
		setcolor(5);
		settextstyle(0,0,4);
		circle(400,400,237);
	
	for(int i=1;i<=12;i++)
	{
		setcolor(5);
		settextstyle(0,0,2);
		outtextxy(400+215*sin(i*PI/6),400-215*cos(i*PI/6),a[i]);
	}
		
		rawtime=time(0);      //with 0 or null return laptop time
		currenttime=localtime(&rawtime);
		
		setcolor(3);
		settextstyle(3,0,7);
		outtextxy(190,70,"ANALOG CLOCK");
		
		
		setcolor(GREEN);
		setlinestyle(0,0,4);
		line(400,400,400+110*sin(currenttime->tm_hour *PI/6),400-110*cos(currenttime->tm_hour*PI/6));
		
		setcolor(GREEN);
		setlinestyle(0,0,3);
		line(400,400,400+170*sin(currenttime->tm_min *PI/30), 400-170*cos(currenttime->tm_min *PI/30));
		
		setcolor(GREEN);
		setlinestyle(0,0,1);
		line(400,400,400+160*sin(currenttime->tm_sec*PI/30),400-160*cos(currenttime->tm_sec*PI/30));

	 	delay(1000);
	 	cleardevice();
	}
	getch();
	closegraph();
	
}
