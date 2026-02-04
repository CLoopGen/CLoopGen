#include <stdio.h>
#include <stdlib.h>

typedef long BLASLONG;

float *b;
BLASLONG ii;
float *ao1;
float *ao2;
float *ao3;
float *ao4;

#define DATA_SIZE (64 << 20) // 64 MB of data per array

static float *b_data;
static float *ao1_data;
static float *ao2_data;
static float *ao3_data;
static float *ao4_data;

void init_vars() {
    b_data = (float*)aligned_alloc(32, DATA_SIZE);
    ao1_data = (float*)aligned_alloc(32, DATA_SIZE);
    ao2_data = (float*)aligned_alloc(32, DATA_SIZE);
    ao3_data = (float*)aligned_alloc(32, DATA_SIZE);
    ao4_data = (float*)aligned_alloc(32, DATA_SIZE);

    b = b_data;
    ao1 = ao1_data;
    ao2 = ao2_data;
    ao3 = ao3_data;
    ao4 = ao4_data;

    for (int i = 0; i < DATA_SIZE / sizeof(float); i++) {
        ao1_data[i] = 1.0f + i;
        ao2_data[i] = 2.0f + i;
        ao3_data[i] = 3.0f + i;
        ao4_data[i] = 4.0f + i;
        b_data[i] = 0.0f;
    }
}