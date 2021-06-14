#include <conio.h>
#include <graphics.h>
#include <time.h>
#include <dos.h>
#include <string.h>

int main() {
    int gd = DETECT, gm;
    long current_time;
    char timeStr[256];
    initgraph(&gd, &gm, "");

    while (!kbhit()) {
        cleardevice();

        /* Get Current time in seconds */
        current_time = time(NULL);

        /* store the date and time in string */
        strcpy(timeStr, ctime(&current_time));
        setcolor(WHITE);
        settextjustify(CENTER_TEXT, CENTER_TEXT);

        moveto(300, 250);

        /* print current time */
        outtext(timeStr);

        /* Add delay of 1000 milliseconds(1 second) */
        delay(1000);
    }

    getch();
    closegraph();
    return 0;
}
