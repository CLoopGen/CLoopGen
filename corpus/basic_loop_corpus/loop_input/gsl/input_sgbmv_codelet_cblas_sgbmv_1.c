#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float beta;
float *Y;
int incY;
int i;
int lenY;
int iy;

void init_vars() {
    lenY = 65536000; // Approximately 256MB of float data (65536000 * sizeof(float) ≈ 256MB)
    beta = 1.5f;
    incY = 1;
    iy = 0;

    Y = (float *)aligned_alloc(32, lenY * sizeof(float));
    if (!Y) {
        exit(1);
    }

    for (int j = 0; j < lenY; j++) {
        Y[j] = (float)(j % 1000);
    }
}