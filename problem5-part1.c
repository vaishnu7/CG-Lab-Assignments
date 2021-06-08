#include <graphics.h>
#include <stdlib.h>

void drawCircle(int x0, int y0, int radius) {
  int x = radius;
  int y = 0;
  int p = 0;

  while (x >= y) {
    putpixel(x0 + x, y0 + y, 7);
    putpixel(x0 + x, y0 - y, 7);
    putpixel(x0 - x, y0 + y, 7);
    putpixel(x0 - x, y0 - y, 7);

    putpixel(x0 + y, y0 + x, 7);
    putpixel(x0 + y, y0 - x, 7);
    putpixel(x0 - y, y0 + x, 7);
    putpixel(x0 - y, y0 - x, 7);

    if (p <= 0) {
      y++;
      p += 2 * y + 1;
    }
    if (p > 0) {
      x--;
      p -= 2 * x + 1;
    }
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

  drawCircle(x, y, radius);

  printf("Press any key to continue: ");
  getch();

  closegraph();

  return EXIT_SUCCESS;
}
