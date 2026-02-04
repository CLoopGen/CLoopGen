#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

unsigned short **imY;
int x_pos = 100;
int x;
int maxold_x = 200;
int result = 0;
int pres_x;
int pres_y = 100;
int COEF[6] = {1, 2, 3, 4, 5, 6};

void init_vars() {
    const int rows = 201;
    const int cols = 201;
    imY = (unsigned short**)calloc(rows, sizeof(unsigned short*));
    for (int i = 0; i < rows; ++i) {
        imY[i] = (unsigned short*)calloc(cols, sizeof(unsigned short));
        for (int j = 0; j < cols; ++j) {
            imY[i][j] = rand() % 256;
        }
    }
    x_pos = 100;
    maxold_x = 200;
    pres_y = 100;
    result = 0;
}