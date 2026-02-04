#include <stdio.h>

typedef long BLASLONG;

BLASLONG m = 100000;
BLASLONG lda = 2;
float *b;
BLASLONG i;
BLASLONG ii = 0;
BLASLONG jj = 0;
BLASLONG k;
float *a1;

static float b_data[200000];
static float a1_data[200000];

void init_vars() {
    ii = 0;
    jj = 0;
    b = b_data;
    a1 = a1_data;
    
    for (BLASLONG idx = 0; idx < 200000; idx++) {
        a1_data[idx] = 1.0F + (idx % 3);
    }
    
    for (BLASLONG idx = 0; idx < 200000; idx++) {
        b_data[idx] = 0.0F;
    }
}