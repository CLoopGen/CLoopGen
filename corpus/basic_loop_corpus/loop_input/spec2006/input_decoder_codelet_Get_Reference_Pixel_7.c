#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

unsigned short **imY;
int x_pos;
int x;
int maxold_x;
int result;
int pres_x;
int pres_y;
int COEF[6];

void init_vars() {
    // Initialize scalar variables to ensure valid array indexing
    x_pos = 100;
    maxold_x = 200;
    pres_y = 50;
    result = 0;

    // Initialize COEF array
    COEF[0] = 1;
    COEF[1] = 2;
    COEF[2] = 3;
    COEF[3] = 4;
    COEF[4] = 5;
    COEF[5] = 6;

    // Allocate imY as a 2D array with dimensions larger than access range
    // We need at least (pres_y + 1) rows and (maxold_x + 1) columns
    int rows = 100;
    int cols = maxold_x + 10; // Add padding

    imY = (unsigned short**)malloc(rows * sizeof(unsigned short*));
    for (int i = 0; i < rows; i++) {
        imY[i] = (unsigned short*)malloc(cols * sizeof(unsigned short));
        memset(imY[i], 1, cols * sizeof(unsigned short)); // Initialize with non-zero
    }
}

// Ensure definitions are available for linking
unsigned short **imY;
int x_pos;
int x;
int maxold_x;
int result;
int pres_x;
int pres_y;
int COEF[6];