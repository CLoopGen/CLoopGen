#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

unsigned short **imY;
int y_pos = 10;
int y;
int maxold_y = 1000;
int result = 0;
int pres_x = 50;
int pres_y;
int COEF[6] = {1, -3, 4, -4, 3, -1};

#define HEIGHT 1000
#define WIDTH  1000

void init_vars() {
    imY = (unsigned short**)calloc(HEIGHT, sizeof(unsigned short*));
    for (int i = 0; i < HEIGHT; i++) {
        imY[i] = (unsigned short*)calloc(WIDTH, sizeof(unsigned short));
        for (int j = 0; j < WIDTH; j++) {
            imY[i][j] = (unsigned short)((i * WIDTH + j) % 65535);
        }
    }
    y_pos = 500;
    maxold_y = HEIGHT - 1;
    pres_x = WIDTH / 2;
    result = 0;
}