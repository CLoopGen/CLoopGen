#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double *Y;
int incY;
int i;
int lenY;
int iy;

void init_vars() {
    lenY = 16777216; // 16M elements, roughly 128MB for double array
    Y = (double*)aligned_alloc(32, lenY * sizeof(double));
    if (Y == NULL) {
        exit(1);
    }
    incY = 1;
    iy = 0;
}