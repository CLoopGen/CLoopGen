#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef long BLASLONG;

BLASLONG m = 512;
BLASLONG n = 512;
float *a;
float *b;
float *c;
BLASLONG ldc = 512;
float aa;
float bb;
int i;
int j;
int k;

static float a_data[512 * 512];
static float b_data[512 * 512];
static float c_data[512 * 512];

void init_vars() {
    a = a_data;
    b = b_data;
    c = c_data;
    ldc = 512;
    m = 512;
    n = 512;

    for (int idx = 0; idx < 512 * 512; idx++) {
        a_data[idx] = (float)(idx % 128) / 64.0f;
        b_data[idx] = 0.0f;
        c_data[idx] = (float)(idx % 256) / 128.0f;
    }
}