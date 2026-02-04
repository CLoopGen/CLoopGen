#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float * imc_exp_tab2;
int *levlCoeffBuf;
float *old_floor;
float *flcoeffs1;
float *flcoeffs2;
int i;

void init_vars() {
    const int size = 32;

    imc_exp_tab2 = (float *)malloc(sizeof(float) * 16);
    levlCoeffBuf = (int *)malloc(sizeof(int) * size);
    old_floor = (float *)malloc(sizeof(float) * size);
    flcoeffs1 = (float *)malloc(sizeof(float) * size);
    flcoeffs2 = (float *)malloc(sizeof(float) * size);

    for (int j = 0; j < 16; j++) {
        imc_exp_tab2[j] = (float)(j * 0.1);
    }

    for (int j = 0; j < size; j++) {
        levlCoeffBuf[j] = rand() % 20;
        old_floor[j] = (float)(j * 1.5);
        flcoeffs1[j] = 0.0f;
        flcoeffs2[j] = (float)(j * 0.5);
    }
}