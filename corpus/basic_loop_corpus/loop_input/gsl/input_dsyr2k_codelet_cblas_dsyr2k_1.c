#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N;
double *C;
int ldc;
int i;
int j;

void init_vars() {
    N = 10000;
    ldc = N;
    C = (double*)calloc(N * ldc, sizeof(double));
}

void loop();