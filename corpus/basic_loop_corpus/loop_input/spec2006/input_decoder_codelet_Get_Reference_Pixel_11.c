#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

unsigned short **imY;
int y_pos = 10;
int x_pos = 10;
int x;
int y;
int maxold_x = 20;
int maxold_y = 20;
int result;
int pres_x;
int pres_y;
int tmp_res[6];
int COEF[6] = {1, 2, 3, 4, 5, 6};

void init_vars() {
    const int data_size = 1 << 20; // ~2MB of data (adjustable)
    const int rows = 1024;
    const int cols = 1024;

    imY = (unsigned short**)calloc(rows, sizeof(unsigned short*));
    unsigned short* backing_store = (unsigned short*)calloc(data_size, sizeof(unsigned short));
    
    for (int i = 0; i < rows; i++) {
        imY[i] = backing_store + i * cols;
        for (int j = 0; j < cols; j++) {
            imY[i][j] = (unsigned short)((i * cols + j) % 65535);
        }
    }

    x_pos = 512;
    y_pos = 512;
    maxold_x = 1023;
    maxold_y = 1023;
}