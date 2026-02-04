#include <stdio.h>

typedef long BLASLONG;

BLASLONG m = 1024;
BLASLONG n = 64;
float beta_r = 1.5f;
float beta_i = 0.8f;
BLASLONG ldc = 2048;
BLASLONG i;
BLASLONG j;

float *c_offset;
float *c_offset1;

float atemp1;
float atemp2;
float atemp3;
float atemp4;
float btemp1;
float btemp2;
float btemp3;
float btemp4;
float ctemp1;
float ctemp2;
float ctemp3;
float ctemp4;

static float c_array[2048 * 64] __attribute__((aligned(32)));

void init_vars() {
    c_offset = c_array;
    c_offset1 = c_array;
}