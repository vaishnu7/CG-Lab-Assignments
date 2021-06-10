#include <conio.h>
#include <dos.h>
#include <graphics.h>
#include <stdbool.h>
#include <stdlib.h>

int main() {
  bool light = false;
  int gd = DETECT, gm;
  initgraph(&gd, &gm, "");

while (!kbhit()) {
    cleardevice();
    // rectangle and line functions to draw the torch
    rectangle(50, 200, 250, 300);
    line(250, 300, 350, 400);
    line(250, 200, 350, 100);
    line(350, 400, 350, 100);

    if (light) {
        //the light
      setfillstyle(SOLID_FILL, YELLOW);
      int arr[] = {350, 400, 650, 450, 650, 50, 350, 100};
      fillpoly(4, arr);
    }

    if (ismouseclick(WM_LBUTTONDOWN))

	{
	    clearmouseclick(WM_LBUTTONDOWN);
	    light = !light;
	    printf("clicked \n");
	}
	delay(50);
  }
  getch();
  closegraph();

  return EXIT_SUCCESS;
}
