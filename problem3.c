#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//global variables defined here

#define WIDTH 60
#define HEIGHT 20
#define X WIDTH/2
#define Y HEIGHT/2
#define XMAX WIDTH-X-1
#define XMIN -(WIDTH-X)
#define YMAX HEIGHT-Y
#define YMIN -(HEIGHT-Y)+1

char grid[HEIGHT][WIDTH] ; //2-D character array used to store the pattern
char text[5][5] = {"0.0", "+1.0", "-1.0"};

int plot_pixel(int x, int y);
void initial_grid(void);
void show_grid(void);
int main()
{
    float x,y;
    initial_grid(); //calling the function init_grid()
    for(x=-3.14159;x<=3.14159;x+=0.1)
    {
        y = sin(x); //sinusoidal function
        plot_pixel(rintf(x*10),rintf(y*8)); //calling the function plot_pixel(int x, int y)
        //rintf()used to round a floating number to its nearest integer
    }
    plot_text("0.0", 0, 0);
    plot_text("+1.0", 0, 1);
    plot_text("-1.0", 0, -1);
    show_grid(); //calling the function show_grid(void)
    return(0);
}

//setting pixels at coordinates
int plot_pixel(int x, int y)
{
    grid[Y-y][X+x] = '*'; //this will plot the wave
    return(0);
}

//initialization of grid
void initial_grid(void)
{
    int x,y;

    for(y=0;y<HEIGHT;y++)
        for(x=0;x<WIDTH+1;x++)
            grid[y][x] = ' ';
    //the axis
    for(y=0;y<HEIGHT;y++)
        grid[y][X] = '#';
    for(x=0;x<WIDTH+1;x++)
        grid[Y][x] = '#';

}
//print the grid
void show_grid(void)
{
    int x,y;
    for(y=0;y<HEIGHT;y++)
    {
        for(x=0;x<WIDTH+1;x++)
            putchar(grid[y][x]);
        putchar('\n');
    }
}
void plot_text(char *text, double x, double y) {
  size_t len = strlen(text);
  size_t index = 0;
  int px = rintf(x*10);
  int py = Y-rintf(y*8);

  while (index < len && px < WIDTH) {
    grid[py][px] = text[index];
    index++;
    px++;
  }
}
