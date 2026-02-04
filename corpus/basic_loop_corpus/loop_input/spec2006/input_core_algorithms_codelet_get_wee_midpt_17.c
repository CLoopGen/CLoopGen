#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int k1 = 0;
int k3 = 1000;
int nxt = 500;
int k;

int **mmx;
int **imx;
int **dmx;

void init_vars() {
    const int rows = 1000;
    const int cols = 2000;

    mmx = (int**)calloc(rows, sizeof(int*));
    imx = (int**)calloc(rows, sizeof(int*));
    dmx = (int**)calloc(rows, sizeof(int*));

    for (int i = 0; i < rows; i++) {
        mmx[i] = (int*)malloc(cols * sizeof(int));
        imx[i] = (int*)malloc(cols * sizeof(int));
        dmx[i] = (int*)malloc(cols * sizeof(int));
    }

    k1 = 0;
    k3 = cols - 2;
    nxt = rows / 2;

    if (nxt >= rows) nxt = rows - 1;
}