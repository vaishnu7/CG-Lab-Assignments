#include <conio.h>
#include <dos.h>
#include <graphics.h>
#include <process.h>
#include <stdlib.h>

const int grid = 70;
const int pad = 50;
const int half = 30;

const int xwins[8][3] = {
    {0, 0, 0}, {1, 1, 1}, {2, 2, 2}, {0, 1, 2},
    {0, 1, 2}, {0, 1, 2}, {0, 1, 2}, {0, 1, 2},
};
const int ywins[8][3] = {
    {0, 1, 2}, {0, 1, 2}, {0, 1, 2}, {0, 0, 0},
    {1, 1, 1}, {2, 2, 2}, {0, 1, 2}, {2, 1, 0},
};
const char players[] = {'X', 'O'};

void drawLines() {
  // vertical lines
  line(grid + pad, pad, grid + pad, 3 * grid + pad);
  line(2 * grid + pad, pad, 2 * grid + pad, 3 * grid + pad);
  // horizontal lines
  line(pad, grid + pad, pad + 3 * grid, grid + pad);
  line(pad, 2 * grid + pad, pad + 3 * grid, 2 * grid + pad);
}

void drawChars(char data[3][3]) {
  for (size_t i = 0; i < 3; i++) {
    for (size_t j = 0; j < 3; j++) {
      char buf[] = " ";
      buf[0] = data[i][j];
      outtextxy(pad + i * grid + half, pad + i * grid + half, buf);
    }
  }
}

char checkWin(char data[3][3]) {
  for (size_t pid = 0; pid < 2; pid++) {
    char player = players[pid];
    for (size_t move = 0; move < 8; move++) {
      size_t count = 0;
      for (size_t idx = 0; idx < 3; idx++) {
        int x = xwins[move][idx];
        int y = ywins[move][idx];
        if (data[x][y] == player) {
          count++;
        }
      }
      if (count == 3) {
        return player;
      }
    }
  }
  return ' ';
}

int main() {
  int gd = DETECT, gm;
  initgraph(&gd, &gm, "");
  setcolor(15);

  char data[3][3];
  for (size_t i = 0; i < 3; i++) {
    for (size_t j = 0; j < 3; j++) {
      data[i][j] = ' ';
    }
  }

  drawLines();

  bool done = false;
  char turn = 'X', winner = ' ';
  size_t count = 0;

  while (!done) {
    int x, y;

    if (ismouseclick(WM_LBUTTONDOWN)) {
      getmouseclick(WM_LBUTTONDOWN, x, y);
      clearmouseclick(WM_LBUTTONDOWN);
    } else {
      delay(100);
      continue;
    }

    int i = (x - pad) / grid;
    int j = (y - pad) / grid;

    if (i < 0 || i >= 3) {
      continue;
    }
    if (j < 0 || j >= 3) {
      continue;
    }

    if (data[i][j] != ' ') {
      continue;
    }

    data[i][j] = turn;
    char buf[] = " ";
    buf[0] = turn;
    outtextxy(pad + i * grid + half, pad + j * grid + half, buf);
    turn = turn == 'X' ? 'O' : 'X';
    count++;
    winner = checkWin(data);
    if (count == 9 || winner != ' ') {
      done = true;
    }
  }

  if (winner == ' ') {
    outtextxy(pad, grid * 4 + pad, "Draw!");
  } else {
    char buf[] = "X wins!";
    buf[0] = winner;
    outtextxy(pad, grid * 4 + pad, buf);
  }

  getch();
  closegraph();
  return EXIT_SUCCESS;
}
//this code has a combined contribution
