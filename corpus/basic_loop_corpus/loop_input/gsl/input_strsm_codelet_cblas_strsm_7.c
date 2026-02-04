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
    n1 = 4096;
    n2 = 4096;
    ldb = n2;
    alpha = 1.5f;

    B = (float*)aligned_alloc(32, n1 * ldb * sizeof(float));
    if (!B) exit(1);

    for (int idx = 0; idx < n1 * ldb; idx++) {
        B[idx] = 2.0f;
    }
}