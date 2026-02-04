#include <stdio.h>
#include <stdlib.h>

typedef long BLASLONG;

BLASLONG m;
BLASLONG i;

float *a_offset1;
float *a_offset2;
float *b_offset;

float a1;
float a2;
float a3;
float a4;

static float *a_storage1;
static float *a_storage2;
static float *b_storage;

void init_vars() {
    const size_t total_size_bytes = 64 * 1024 * 1024; // 64 MB total data size
    const size_t floats_per_array = total_size_bytes / (sizeof(float) * 2); // two arrays, each with float pairs

    a_storage1 = (float*)aligned_alloc(32, floats_per_array * sizeof(float));
    a_storage2 = (float*)aligned_alloc(32, floats_per_array * sizeof(float));
    b_storage  = (float*)aligned_alloc(32, floats_per_array * sizeof(float));

    if (!a_storage1 || !a_storage2 || !b_storage) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t j = 0; j < floats_per_array; j++) {
        a_storage1[j] = (float)(j % 127) + 1.0f;
        a_storage2[j] = (float)(j % 127) + 2.0f;
        b_storage[j]  = 0.0f;
    }

    a_offset1 = a_storage1;
    a_offset2 = a_storage2;
    b_offset = b_storage;

    m = floats_per_array / 2; // because loop processes 2 elements per iteration
}