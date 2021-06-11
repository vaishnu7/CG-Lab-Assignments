#include <conio.h>
#include <dos.h>
#include <graphics.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int gd = DETECT, gm;
  initgraph(&gd, &gm, "");

  // Initialize RNG
  srand(time(NULL));

  bool running = true;
  size_t ball_limit = 5;
  size_t ball_count = 0;
  int score = 0;

  const int radius = 20;
  const int width = getmaxx();
  const int padding = 25;

  int bucket_x0[] = {70, 220, 450};
  int bucket_x1[] = {150, 370, 530};
  size_t bucket_limit = sizeof(bucket_x0) / sizeof(int);
  int bucket_y0 = 270;
  int bucket_y1 = 350;
  int bucket_sc[] = {10, 20, 10};

  while (!kbhit()) {
    cleardevice();
    outtextxy(width / 2 - 10, 250, "Press any key to start.");
    delay(20);
  }

  while (running) {
    ball_count++;
    if (ball_count >= ball_limit) {
      running = false;
      break;
    }
    int x = rand() % (width - 2 * padding) + padding;
    int y = 20;

    while (y < 400) {
      cleardevice();

      for (size_t i = 0; i < bucket_limit; i++) {
        line(bucket_x0[i], bucket_y0, bucket_x0[i], bucket_y1);
        line(bucket_x0[i], bucket_y1, bucket_x1[i], bucket_y1);
        line(bucket_x1[i], bucket_y1, bucket_x1[i], bucket_y0);

        char score_buf[10];
        sprintf(score_buf, "%d", bucket_sc[i]);
        outtextxy((bucket_x0[i] + bucket_x1[i]) / 2,
                  (bucket_y0 + bucket_y1) / 2, score_buf);
      }

      char buf[30];
      sprintf(buf, "Score: %d", score);
      outtextxy(10, 20, buf);

      circle(x, y, radius);
      y += 10;

      delay(60);
    }

    for (size_t i = 0; i < bucket_limit; i++) {
      if (x >= bucket_x0[i] && x <= bucket_x1[i]) {
        score += bucket_sc[i];
        break;
      }
    }
  }

  cleardevice();

  char final_text[50];
  sprintf(final_text, "Final score is: %d", score);
  outtextxy(width / 2 - 10, 250, final_text);

  delay(10000);

  while (!kbhit()) {
    delay(20);
  }

  getch();
  closegraph();

  return EXIT_SUCCESS;
}
