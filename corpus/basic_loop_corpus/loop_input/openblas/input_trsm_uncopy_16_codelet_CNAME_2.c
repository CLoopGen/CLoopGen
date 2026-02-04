#include <stdio.h>

typedef long BLASLONG;

BLASLONG m = 100000;
BLASLONG lda = 4;
float *b;
BLASLONG i;
BLASLONG ii = 0;
BLASLONG jj = 0;
BLASLONG k;

float *a1;
float *a2;
float *a3;
float *a4;

static float b_data[400000];
static float a1_data[400000];
static float a2_data[400000];
static float a3_data[400000];
static float a4_data[400000];

void init_vars() {
    b = b_data;
    a1 = a1_data;
    a2 = a2_data;
    a3 = a3_data;
    a4 = a4_data;

    for (int idx = 0; idx < 400000; idx++) {
        a1_data[idx] = 1.0f + idx * 0.0001f;
        a2_data[idx] = 2.0f + idx * 0.0001f;
        a3_data[idx] = 3.0f + idx * 0.0001f;
        a4_data[idx] = 4.0f + idx * 0.0001f;
        b_data[idx] = 0.0f;
    }
}