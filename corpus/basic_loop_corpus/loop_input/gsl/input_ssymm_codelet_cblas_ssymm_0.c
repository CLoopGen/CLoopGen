#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *C;
int ldc;
int i;
int j;
int n1;
int n2;

void init_vars() {
    n1 = 4096;
    n2 = 4096;
    ldc = n2;

    C = (float*)aligned_alloc(32, n1 * n2 * sizeof(float));
}