/*Circle Moving from left to right*/

#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>
#include<dos.h>

int xc=100, yc=200, rad=100;
void drawcircles()
{
        setcolor(WHITE);
        circle(xc,yc,rad);
}
int main()
{
        int i,a;
        int gd=DETECT,gm;
        initgraph(&gd,&gm,"");
        a=xc+rad;
        while(!kbhit())
        {
                while(a<=630)
                {
                        cleardevice();
                        drawcircles();
                        xc+=2;
                        a=xc+rad;
                        delay(20);
                }
                xc=100;  rad=100; a=xc+rad;
        }
        getch();
        closegraph();
        return 0;
}
