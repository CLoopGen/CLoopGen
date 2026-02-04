#include <stdlib.h>
#include <stdint.h>

double *Y;
int incY;
int i;
int lenY;
int iy;

void init_vars() {
    lenY = 16777216;  // 16M elements, ~128 MB for double array
    Y = (double*)aligned_alloc(32, lenY * sizeof(double));
    incY = 1;
    iy = 0;
}