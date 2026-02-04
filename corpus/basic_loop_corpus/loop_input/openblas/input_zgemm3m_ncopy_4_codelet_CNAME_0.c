#include <stdio.h>
#include <stdlib.h>

typedef long BLASLONG;

BLASLONG m;
BLASLONG i;
float *a_offset1;
float *a_offset2;
float *a_offset3;
float *a_offset4;
float *b_offset;
float a1;
float a2;
float a3;
float a4;
float a5;
float a6;
float a7;
float a8;

static float *a1_data;
static float *a2_data;
static float *a3_data;
static float *a4_data;
static float *b_data;

void init_vars() {
    const size_t vector_size = 64 * 1024 * 1024 / sizeof(float); // ~256MB total data
    m = vector_size / 2;

    a1_data = (float*)malloc(vector_size * sizeof(float));
    a2_data = (float*)malloc(vector_size * sizeof(float));
    a3_data = (float*)malloc(vector_size * sizeof(float));
    a4_data = (float*)malloc(vector_size * sizeof(float));
    b_data = (float*)malloc(vector_size * 2 * sizeof(float));

    a_offset1 = a1_data;
    a_offset2 = a2_data;
    a_offset3 = a3_data;
    a_offset4 = a4_data;
    b_offset = b_data;

    for (size_t i = 0; i < vector_size; i++) {
        a1_data[i] = 1.0f;
        a2_data[i] = 2.0f;
        a3_data[i] = 3.0f;
        a4_data[i] = 4.0f;
    }
    for (size_t i = 0; i < vector_size * 2; i++) {
        b_data[i] = 0.0f;
    }
}