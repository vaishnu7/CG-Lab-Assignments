#include <stdio.h>
#include <graphics.h>
#include <math.h>

int x [4] = {200,90,250,250};
int y [4] = {300,150,45,60};

void bezier_curve ()
{
int i;
double t, xt, yt;
for (t = 0.0; t < 1.0; t += 0.005)
{
xt = pow(1-t,3) * x [0] + 3*t*pow(1-t,2) * x [ 1] + 3*pow(t,2) * (1-t) * x [2] + pow(t,3) * x [3];
yt = pow(1-t,3) * y [0] + 3*t*pow(1-t,2) * y [1] + 3*pow(t,2) * (1-t) * y [2] + pow(t,3) * y [3];
putpixel (xt, yt,WHITE);
}

getch ();
closegraph ();
}

int main ()
{
int gd = DETECT, gm;
initgraph (&gd, &gm, "");
bezier_curve ();
}
