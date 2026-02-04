#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double *C;
int ldc;
int i;
int j;
int n1;
int n2;

void init_vars() {
    n1 = 4096;
    n2 = 4096;
    ldc = n2;

    C = (double*)aligned_alloc(32, sizeof(double) * ldc * n1);
    if (!C) {
        exit(1);
    }
}