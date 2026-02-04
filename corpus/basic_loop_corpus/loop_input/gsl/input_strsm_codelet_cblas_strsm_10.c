#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *A;
int lda;
float *B;
int ldb;
int i;
int j;
int k;
int n1;
int n2;
int nonunit;

static float A_data[8192];
static float B_data[8192];

void init_vars() {
    n1 = 64;
    n2 = 64;
    nonunit = 1;
    lda = 64;
    ldb = 64;

    A = A_data;
    B = B_data;

    for (int idx = 0; idx < 8192; ++idx) {
        A_data[idx] = 1.0f + 0.01f * (idx % 100);
        B_data[idx] = 0.5f * (idx % 50);
    }
}