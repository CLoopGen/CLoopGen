#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double beta = 2.5;

double *Y;
int incY = 1;
int i;
int lenY;
int iy;

void init_vars() {
    lenY = 32 * 1024 * 1024; // Approximately 256 MB of double data (32M elements)
    Y = (double*)aligned_alloc(32, lenY * sizeof(double));
    if (!Y) {
        exit(1);
    }
    for (int j = 0; j < lenY; j++) {
        Y[j] = (double)(j + 1);
    }
    iy = 0;
}