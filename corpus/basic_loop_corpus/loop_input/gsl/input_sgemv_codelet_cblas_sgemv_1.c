#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float beta = 1.5f;

static float Y_data[65536]; 
float *Y = Y_data;
int incY = 1;
int i;
int lenY = 65536;
int iy = 0;

void init_vars() {
    for (int j = 0; j < lenY; j++) {
        Y_data[j] = (float)(j % 128);
    }
    beta = 1.75f;
    incY = 1;
    iy = 0;
}