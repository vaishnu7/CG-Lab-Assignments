#include <graphics.h>
#include <math.h>
#include <stdlib.h>

void drawFlower(int x0, int y0, int radius) {
  circle(x0, y0, radius / 6);

  const float k = 8;
  for (float theta = 0; theta < 2 * M_PI; theta += 0.001f) {
    float scale = radius * cos(k * theta);
    int x = (int)scale * cos(theta);
    int y = (int)scale * sin(theta);
    putpixel(x0 + x, y0 + y, 14);
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

  printf("Press any key to continue: ");
  getch();

  closegraph();

  return EXIT_SUCCESS;
}
