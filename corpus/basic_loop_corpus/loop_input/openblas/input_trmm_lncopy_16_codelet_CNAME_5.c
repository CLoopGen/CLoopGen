#include <stdio.h>

typedef long BLASLONG;

float *b;
BLASLONG i;
BLASLONG ii;
float *a01;
float *a02;
float *a03;
float *a04;

static float *b_storage;
static float *a01_storage;
static float *a02_storage;
static float *a03_storage;
static float *a04_storage;

void init_vars() {
    const BLASLONG size = 65536 * 4; // ~1MB of data per array, allows for ~65k iterations with 4-wide store
    i = size / 4;

    b_storage = (float*)__builtin_malloc(size * sizeof(float));
    a01_storage = (float*)__builtin_malloc(size * sizeof(float));
    a02_storage = (float*)__builtin_malloc(size * sizeof(float));
    a03_storage = (float*)__builtin_malloc(size * sizeof(float));
    a04_storage = (float*)__builtin_malloc(size * sizeof(float));

    b = b_storage;
    a01 = a01_storage;
    a02 = a02_storage;
    a03 = a03_storage;
    a04 = a04_storage;

    for (BLASLONG j = 0; j < size; j++) {
        a01_storage[j] = 1.0f + j * 0.0001f;
        a02_storage[j] = 2.0f + j * 0.0001f;
        a03_storage[j] = 3.0f + j * 0.0001f;
        a04_storage[j] = 4.0f + j * 0.0001f;
        b_storage[j] = 0.0f;
    }
}