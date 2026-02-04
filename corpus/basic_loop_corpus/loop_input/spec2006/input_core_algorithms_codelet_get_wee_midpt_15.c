#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int k1 = 0;
int k3 = 10000;

int cur = 0;

int k;

int **mmx;
int **imx;
int **dmx;

void init_vars() {
    const int rows = 1;
    const int cols = k3 + 1; 

    mmx = (int**)calloc(rows, sizeof(int*));
    imx = (int**)calloc(rows, sizeof(int*));
    dmx = (int**)calloc(rows, sizeof(int*));

    for (int i = 0; i < rows; i++) {
        mmx[i] = (int*)malloc(cols * sizeof(int));
        imx[i] = (int*)malloc(cols * sizeof(int));
        dmx[i] = (int*)malloc(cols * sizeof(int));
    }
}