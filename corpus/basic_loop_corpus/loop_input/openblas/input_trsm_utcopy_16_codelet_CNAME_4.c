#include <stdio.h>

typedef long BLASLONG;

BLASLONG m = 1000;
BLASLONG lda = 1024;
float *b;
BLASLONG i = 0;
BLASLONG ii = 50;
BLASLONG jj = 50;
BLASLONG k = 0;
float *a1;

static float b_data[1024];
static float a1_data[1024 * 1024];

void init_vars() {
    b = b_data;
    a1 = a1_data;
}