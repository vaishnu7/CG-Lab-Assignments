#include <graphics.h>
#include <math.h>
#include <stdlib.h>

void drawFlower(int x0, int y0, int radius) {
  // Petals
  for (int i = 2; i <= 3; i++) {
    for (float theta = 0; theta < 4 * M_PI; theta += 0.001f) {
      float scale = radius * cos(0.5 * theta) / (1 + i * 0.3);
      int x = (int)scale * cos(theta + i * M_PI / 2.0f);
      int y = (int)scale * sin(theta + i * M_PI / 2.0f);
      putpixel(x0 + x, y0 + y, 4);
      x = (int)scale * cos(theta + (i + 1) * M_PI / 2.0f);
      y = (int)scale * sin(theta + (i + 1) * M_PI / 2.0f);
      putpixel(x0 + x, y0 + y, 4);
    }
       arc(110,275,300,0,162);// stems
       arc(112,295,300,12,164);
       arc(232,295,205,300,50); //leaf
       arc(212,357,20,120,50);
  }
}

int main() {
  int x, y, radius;
  printf("Enter value for midpoint x: ");
  scanf("%d", &x);
  printf("Enter value for midpoint y: ");
  scanf("%d", &y);
  printf("Enter value for radius: ");
  scanf("%d", &radius);

  int gdriver = DETECT, gmode, errorcode;
  initgraph(&gdriver, &gmode, "");
  errorcode = graphresult();

  if (errorcode != grOk) {
    printf("An error occurred: %s\n", grapherrormsg(errorcode));
    printf("Press any key to stop: ");
    getch();

    return EXIT_FAILURE;
  }

  drawFlower(x, y, radius);
  //ellipse(250, 300, 0, 120, 150, 50);
  printf("Press any key to continue: ");
  getch();

  closegraph();

  return EXIT_SUCCESS;
}
