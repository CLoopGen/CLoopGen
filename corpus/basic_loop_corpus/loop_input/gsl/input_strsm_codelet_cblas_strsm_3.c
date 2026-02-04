#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float alpha;
float *B;
int ldb;
int i;
int j;
int n1;
int n2;

void init_vars() {
    alpha = 1.5f;
    n1 = 4096;
    n2 = 4096;
    ldb = n2;
    size_t total_size = (size_t)ldb * n1;
    B = (float*)aligned_alloc(32, total_size * sizeof(float));
    for (size_t idx = 0; idx < total_size; idx++) {
        B[idx] = (float)(idx % 128);
    }
}