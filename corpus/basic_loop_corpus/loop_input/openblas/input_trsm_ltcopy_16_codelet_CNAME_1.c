#include <stdio.h>

typedef long BLASLONG;

BLASLONG m = 100000;
BLASLONG lda = 8;
float *b;
BLASLONG i;
BLASLONG ii = 0;
BLASLONG jj = 0;
BLASLONG k;
float *a1;

static float b_data[800000];
static float a1_data[800000];

void init_vars() {
    for (int idx = 0; idx < 800000; idx++) {
        a1_data[idx] = (float)(idx % 100) + 1.0f;
    }
    for (int idx = 0; idx < 800000; idx++) {
        b_data[idx] = 0.0f;
    }
    b = b_data;
    a1 = a1_data;
    ii = 0;
}