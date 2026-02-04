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
int COEF[6] = {1, -2, 3, -4, 5, -6};

static unsigned short *imY_data;
static int imY_rows = 1024;
static int imY_cols = 1024;

void init_vars() {
    // Allocate a 2D array of size imY_rows x imY_cols (about 2MB of data)
    imY_data = (unsigned short *)calloc(imY_rows * imY_cols, sizeof(unsigned short));
    imY = (unsigned short **)malloc(imY_rows * sizeof(unsigned short *));
    
    for (int i = 0; i < imY_rows; i++) {
        imY[i] = &imY_data[i * imY_cols];
    }

    // Initialize with non-zero values to simulate real data
    for (int i = 0; i < imY_rows; i++) {
        for (int j = 0; j < imY_cols; j++) {
            imY[i][j] = (unsigned short)((i * j + 1) % 32768);
        }
    }

    // Set safe initial values for loop indices and bounds
    y_pos = 512;
    maxold_y = imY_rows - 1;
    pres_x = 512;
    result = 0;
}