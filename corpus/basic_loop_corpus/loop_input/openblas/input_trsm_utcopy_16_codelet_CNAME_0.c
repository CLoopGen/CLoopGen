#include <stdio.h>

typedef long BLASLONG;

BLASLONG m = 10000;
BLASLONG lda = 16;
float *b;
BLASLONG i;
BLASLONG ii = 20;
BLASLONG jj = 10;
BLASLONG k;
float *a1;

float b_data[160000];
float a1_data[160000];

void init_vars() {
    for (int idx = 0; idx < 160000; idx++) {
        b_data[idx] = 0.0f;
        a1_data[idx] = (idx % 32) + 1.0f;
    }
    b = b_data;
    a1 = a1_data;
}