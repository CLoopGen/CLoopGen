#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int M = 10000;

int **mmx;
int **imx;
int **dmx;
int k;

void init_vars() {
    mmx = (int**)calloc(1, sizeof(int*));
    imx = (int**)calloc(1, sizeof(int*));
    dmx = (int**)calloc(1, sizeof(int*));

    mmx[0] = (int*)malloc((M + 1) * sizeof(int));
    imx[0] = (int*)malloc((M + 1) * sizeof(int));
    dmx[0] = (int*)malloc((M + 1) * sizeof(int));

    for (int i = 0; i <= M; i++) {
        mmx[0][i] = 0;
        imx[0][i] = 0;
        dmx[0][i] = 0;
    }
}