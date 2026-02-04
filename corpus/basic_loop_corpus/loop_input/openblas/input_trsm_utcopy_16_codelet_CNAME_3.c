#include <stdio.h>

typedef long BLASLONG;

BLASLONG m = 100000;
BLASLONG lda = 2;
float *b;
BLASLONG i;
BLASLONG ii = 2;
BLASLONG jj = 1;
BLASLONG k;
float *a1;

static float b_data[200000];
static float a1_data[200000];

void init_vars() {
    for (int idx = 0; idx < 200000; idx++) {
        b_data[idx] = 0.0f;
        a1_data[idx] = (idx % 3) + 1.0f;
    }
    b = b_data;
    a1 = a1_data;
}