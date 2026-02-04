#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 1024;
int ldc = 1024;
int i, j;

void *C;

void init_vars() {
    size_t total_elements = ldc * N;
    float *c_data = (float *)calloc(total_elements * 2, sizeof(float));
    C = c_data;
}