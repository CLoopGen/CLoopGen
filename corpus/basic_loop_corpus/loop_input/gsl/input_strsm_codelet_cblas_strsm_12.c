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

static float A_data[2048 * 2048];
static float B_data[2048 * 2048];

void init_vars() {
    n1 = 2048;
    n2 = 2048;
    lda = 2048;
    ldb = 2048;
    nonunit = 1;

    A = A_data;
    B = B_data;

    for (int idx = 0; idx < 2048 * 2048; idx++) {
        A_data[idx] = 1.0f + (idx % 7) * 0.1f;
        B_data[idx] = (idx % 13) * 0.5f;
    }
}