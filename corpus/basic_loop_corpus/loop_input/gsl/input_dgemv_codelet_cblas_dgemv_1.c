#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/time.h>

double beta;
double *Y;
int incY;
int i;
int lenY;
int iy;

static double Y_buffer[65536];

void init_vars() {
    // Initialize scalar variables
    beta = 1.5;
    incY = 1;
    i = 0;
    lenY = 65536;  // Size chosen to ensure reasonable execution time (~0.01 sec)
    iy = 0;

    // Initialize array pointer
    Y = Y_buffer;

    // Initialize Y array with non-zero values for meaningful computation
    for (int j = 0; j < lenY; j++) {
        Y[j] = (double)(j % 1000) + 1.0;
    }
}