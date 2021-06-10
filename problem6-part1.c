#include <graphics.h>
#include <stdlib.h>

void drawEllipse(int x0, int y0, int ra, int rb) {
  int x = 0;
  int y = rb;

  float dy, dx, db, da;

  // First part
  db = (rb * rb) - (ra * ra * rb) + (0.25 * ra * ra);
  dx = 2 * rb * rb * x;
  dy = 2 * ra * ra * y;

  while (dx < dy) {
    putpixel(+x + x0, +y + y0, 7);
    putpixel(-x + x0, +y + y0, 7);
    putpixel(+x + x0, -y + y0, 7);
    putpixel(-x + x0, -y + y0, 7);

    x++;
    if (db < 0) {
      dx = dx + (2 * rb * rb);
      db = db + dx + (rb * rb);
    } else {
      y--;
      dx = dx + (2 * rb * rb);
      dy = dy - (2 * ra * ra);
      db = db + dx - dy + (rb * rb);
    }
  }

  // Second part
  da = ((rb * rb) * ((x + 0.5) * (x + 0.5))) +
       ((ra * ra) * ((y - 1.0) * (y - 1.0))) - (ra * ra * rb * rb);
  while (y >= 0) {
    putpixel(+x + x0, +y + y0, 7);
    putpixel(-x + x0, +y + y0, 7);
    putpixel(+x + x0, -y + y0, 7);
    putpixel(-x + x0, -y + y0, 7);
    if (da > 0) {
      y--;
      dy = dy - (2 * ra * ra);
      da = da + (ra * ra) - dy;
    } else {
      y--;
      x++;
      dx = dx + (2 * rb * rb);
      dy = dy - (2 * ra * ra);
      da = da + dx - dy + (ra * ra);
    }
  }
}

int main() {
  int x, y, ra, rb;
  printf("Enter value for midpoint x: ");
  scanf("%d", &x);
  printf("Enter value for midpoint y: ");
  scanf("%d", &y);
  printf("Enter value for radius a (horizontal): ");
  scanf("%d", &ra);
  printf("Enter value for radius b (vertical)  : ");
  scanf("%d", &rb);

  int gdriver = DETECT, gmode, errorcode;
  initgraph(&gdriver, &gmode, "");
  errorcode = graphresult();

  if (errorcode != grOk) {
    printf("An error occurred: %s\n", grapherrormsg(errorcode));
    printf("Press any key to stop: ");
    getch();
    return EXIT_FAILURE;
  }
  drawEllipse(x, y, ra, rb);
  printf("Press any key to continue: ");
  getch();
  closegraph();
  return EXIT_SUCCESS;
}
