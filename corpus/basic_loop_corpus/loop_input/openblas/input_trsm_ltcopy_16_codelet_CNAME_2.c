#include <stdio.h>
#include <stdlib.h>

typedef long BLASLONG;

BLASLONG m = 100000;
BLASLONG lda = 4;
float *b;
BLASLONG i;
BLASLONG ii = 0;
BLASLONG jj = 0;
BLASLONG k;
float *a1;

float *b_data;
float *a1_data;

void init_vars() {
    b_data = (float *)calloc(m * 4, sizeof(float));
    a1_data = (float *)calloc(m * lda, sizeof(float));

    b = b_data;
    a1 = a1_data;

    for (BLASLONG idx = 0; idx < m * lda; idx++) {
        a1_data[idx] = 1.0F + (idx % 7);
    }
}