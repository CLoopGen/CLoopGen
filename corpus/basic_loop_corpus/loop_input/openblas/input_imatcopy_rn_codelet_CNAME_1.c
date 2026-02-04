#include <stdio.h>

typedef long BLASLONG;

BLASLONG rows = 5000;
BLASLONG cols = 100;
BLASLONG lda = 100;
BLASLONG i;
BLASLONG j;
float *aptr;

static float global_array[5000 * 100] __attribute__((aligned(32)));

void init_vars() {
    aptr = global_array;
}