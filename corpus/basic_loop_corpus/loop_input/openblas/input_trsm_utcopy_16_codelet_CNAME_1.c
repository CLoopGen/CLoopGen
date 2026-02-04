#include <stdio.h>

typedef long BLASLONG;

BLASLONG m = 100000;
BLASLONG lda = 8;
float b_array[800000];
float a1_array[800000];
BLASLONG i = 0;
BLASLONG ii = 10;
BLASLONG jj = 5;
BLASLONG k = 0;
float *b = b_array;
float *a1 = a1_array;

void init_vars() {
    for (int idx = 0; idx < 800000; idx++) {
        a1_array[idx] = (float)(idx + 1);
        b_array[idx] = 0.0f;
    }
}