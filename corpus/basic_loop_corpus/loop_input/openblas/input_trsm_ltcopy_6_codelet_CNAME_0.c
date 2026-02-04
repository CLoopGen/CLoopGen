#include <stdio.h>

typedef long BLASLONG;

BLASLONG m = 100000;
BLASLONG lda = 4;
float b_array[400000];
float a1_array[400000];
BLASLONG i;
BLASLONG ii = 0;
BLASLONG jj = 0;
float *b = b_array;
float *a1 = a1_array;
BLASLONG k;

void init_vars() {
    for (int idx = 0; idx < 400000; idx++) {
        a1_array[idx] = 1.0f + (idx % 4);
    }
}