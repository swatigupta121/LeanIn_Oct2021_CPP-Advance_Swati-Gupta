#include <graphics.h>
#include <stdlib.h>
#include <dos.h>
#include <conio.h>
#include <stdio.h>
#include <time.h>
int m[500],n[500],body=20,flag=0;

void board()
{
      setcolor(WHITE);
      if(flag==1)
		setcolor(RED);
      rectangle(0,0,getmaxx(),getmaxy());
      rectangle(1,1,getmaxx()-1,getmaxy()-1);
      rectangle(2,2,getmaxx()-2,getmaxy()-2);
}

void end(){
    int j,i;
    setcolor(WHITE);
    for(i=0;i<5;i++){
	delay(500);
	cleardevice();
	delay(500);
	for(j=0;j<=body;j++){
		   setfillstyle(SOLID_FILL,RED);
		   circle(m[j],n[j],5);
		   floodfill(m[j],n[j],WHITE);
		  }
	}
    settextstyle(3,0,5);
    outtextxy(150,150,"    GAME OVER ");
    getch();
    getch();
    exit(0);
   }

void check() {
   int a;
   for(a=1;a<body;a++)
       {
	if(m[0]==m[a] && n[0]==n[a]) 
		end();
	}
   }

void win() {
	int j,i;
	setcolor(WHITE);
	for(i=0;i<5;i++){
		for(j=0;j<=body;j++){
			   setfillstyle(SOLID_FILL,body);
			   circle(m[j],n[j],5);
			   floodfill(m[j],n[j],WHITE);
		  }
		delay(500);
		cleardevice();
		delay(500);
	 }
	settextstyle(3,0,5);
	outtextxy(210,320," YOU WIN ");
	getch();
	exit(0);
	}
main(){

	int gd=DETECT,gm,ch,a=0,i=0,j,Xmax,Ymax,temp,x=240,y=450,p,q,speed=100;

	initgraph(&gd,&gm,(char*)"");

	setcolor(WHITE);
	settextstyle(3,0,6);
	outtextxy(200,2," SNAKE.CG");
	settextstyle(6,0,2);
	outtextxy(20,80," Use Arrow Keys To Direct The Snake ");
	outtextxy(20,140," Avoid Collision With The Body To Keep Playing!");
	outtextxy(20,160," Pick The Food Until You Win The Game Or Get Tired!");
	outtextxy(20,200," Press `Esc' Anytime To Exit ");
	outtextxy(20,220," Press 1 For Easy-Mode");
	outtextxy(20,240," Press 2 For Hard-Mode");
	ch=getch();
	if(ch==27) exit(0);
	cleardevice();
	Xmax=getmaxx();
	Ymax=getmaxy();
	if(ch == 50){ flag = 1;}
	board();
//	randomize();
	p=rand()%Xmax + 1;
	temp=p%15;
	p=p-temp;
	q=rand()%Ymax + 1;
	temp=q%15;
	q=q-temp;

	while(1)
	{
	 setcolor(WHITE);
	 setfillstyle(SOLID_FILL,body+5);
	 circle(p,q,5);
	 floodfill(p,q,WHITE);

	 if(kbhit()){
	     ch=getch(); if(ch==0) ch=getch();
	     if(ch==72 && a!=2) a=1;
	     else if(ch==80 && a!=1) a=2;
	     else if(ch==75 && a!=4) a=3;
	     else if(ch==77 && a!=3) a=4;
	   }
	 else{
	     if(ch==27) break;
	   }
	 if(i<20){
		 m[i]=x;
		 n[i]=y;
		 i++;
	       }
	 if(i>=20){

		 for(j=body;j>=0;j--){
			m[j+1]=m[j];
			n[j+1]=n[j];
			}
		 m[0]=x;
		 n[0]=y;

		 setcolor(WHITE);
		 setfillstyle(SOLID_FILL,body);
		 circle(m[0],n[0],8);
		 floodfill(m[0],n[0],WHITE);

		 setcolor(WHITE);
		 for(j=1;j<body;j++){
			 setfillstyle(SOLID_FILL,body+j%3);
			 circle(m[j],n[j],5);
			 floodfill(m[j],n[j],WHITE);
			}
		 delay(speed);
		 board();
		 setcolor(BLACK);
		 setfillstyle(SOLID_FILL,BLACK);
		 circle(m[0],n[0],8);
		 floodfill(m[0],n[0],BLACK);

		 setcolor(BLACK);
		 setfillstyle(SOLID_FILL,BLACK);
		 circle(m[j],n[j],5);
		 floodfill(m[j],n[j],BLACK);

	}
	check();

	if(x==p && y==q) {
	      body += 5;
	      if(speed>=50) speed -= 5;
	      else speed=50;
	      if(body>490) win();
	      p=rand()%Xmax + 1; temp=p%15;  p=p-temp;
	      q=rand()%Ymax + 1; temp=q%15;   q=q-temp;
	}
	if(flag==1)
	{
	if(a==1)  
		y =  y-15; 
		if(y<0) end();
	if(a==2)  
		y =  y+15; 
		if(y>Ymax) end();
	if(a==3)  
		x =  x-15; 
		if(x<0)  end();
	if(a==4)  
		x =  x+15; 
		if(x>Xmax) end();
	}

	if(flag == 0){
	if(a==1)  
		y =  y-15; 
		if(y<0) { 
			temp=Ymax%15;
			y=Ymax-temp;}
	if(a==2)  
		y =  y+15; 
		if(y>Ymax) y=0;
	if(a==3) 
		x =  x-15; 
		if(x<0) { 
			temp=Xmax%15;
			x=Xmax-temp;}
	if(a==4)  
		x =  x+15; 
		if(x>Xmax) x=0;
	}

	if(a==0){ x = x+15; }
      }
return 0;
   }
/*
 p and q decide food coordinates
 x and y make the body of the snake
 m and n store the points of all x and y 
 a is used for deciding directions
 speed increases the delay time
 */
