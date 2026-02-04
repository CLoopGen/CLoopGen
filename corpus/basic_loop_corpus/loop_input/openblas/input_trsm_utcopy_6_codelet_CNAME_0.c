#include <stdio.h>

typedef long BLASLONG;

BLASLONG m = 100000;
BLASLONG lda = 4;
float *b;
BLASLONG i;
BLASLONG ii = 3;
BLASLONG jj = 1;
float *a1;
BLASLONG k;

static float b_data[400000];
static float a1_data[400000];

void init_vars() {
    b = b_data;
    a1 = a1_data;
    
    for (int idx = 0; idx < 400000; idx++) {
        a1_data[idx] = (float)(idx + 1);
    }
}