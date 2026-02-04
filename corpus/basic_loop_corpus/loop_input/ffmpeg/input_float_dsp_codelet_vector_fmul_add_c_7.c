#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

#define DATA_SIZE_MB 64
#define ARRAY_SIZE (DATA_SIZE_MB * (1 << 20) / sizeof(float))

float *dst;
float *src0;
float *src1;
float *src2;
int len;
int i;

void init_vars() {
    len = ARRAY_SIZE;

    dst = (float *)aligned_alloc(32, len * sizeof(float));
    src0 = (float *)aligned_alloc(32, len * sizeof(float));
    src1 = (float *)aligned_alloc(32, len * sizeof(float));
    src2 = (float *)aligned_alloc(32, len * sizeof(float));

    for (int j = 0; j < len; j++) {
        src0[j] = 1.0f + (j % 100) * 0.01f;
        src1[j] = 2.0f + (j % 50)  * 0.02f;
        src2[j] = 3.0f + (j % 25)  * 0.03f;
    }
}