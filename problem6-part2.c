#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>
#include<dos.h>

int xc=100, yc=200, rad=100;
int x[15], y[15];
void drawcircles()
{
        setcolor(LIGHTGRAY);
        circle(xc,yc,rad);
        circle(xc,yc,rad+5);
}
int main()
{
        double angle=0,theta;
        int i,a;
        int gd=DETECT,gm;
        initgraph(&gd,&gm,"");
        a=xc+rad;
        while(!kbhit())
        {
                while(a<=630)
                {
                        theta=M_PI*angle/180;
                        cleardevice();
                        drawcircles();
                        for(i=0;i<18;i++)
                        {
                                theta=M_PI*angle/180;
                                x[i]=xc+rad*cos(theta);
                                y[i]=yc+rad*sin(theta);
                                angle+=20;
                                line(xc,yc,x[i],y[i]);
                        }
                        angle+=2; xc+=2; a=xc+rad;
                        delay(15);
                }
                xc=100;  rad=100; a=xc+rad;
        }
        getch();
        closegraph();
        return 0;
}
