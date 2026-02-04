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
    B = (float*)aligned_alloc(32, sizeof(float) * ldb * n1);
    for (int idx = 0; idx < ldb * n1; idx++) {
        B[idx] = 1.0f;
    }
}