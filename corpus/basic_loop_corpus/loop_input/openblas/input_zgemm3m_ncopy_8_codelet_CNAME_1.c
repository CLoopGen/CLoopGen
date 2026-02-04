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
    const size_t element_size = 2;
    const size_t b_element_size = 4;
    const long total_data_bytes = 128 * 1024 * 1024; 
    const long total_elements = total_data_bytes / (sizeof(float) * (4 * element_size + b_element_size));
    m = total_elements > 0 ? total_elements : 1;

    a1_data = (float*)aligned_alloc(32, m * element_size * sizeof(float));
    a2_data = (float*)aligned_alloc(32, m * element_size * sizeof(float));
    a3_data = (float*)aligned_alloc(32, m * element_size * sizeof(float));
    a4_data = (float*)aligned_alloc(32, m * element_size * sizeof(float));
    b_data = (float*)aligned_alloc(32, m * b_element_size * sizeof(float));

    for (long j = 0; j < m * element_size; j++) {
        a1_data[j] = 1.0f + j * 0.0001f;
        a2_data[j] = 2.0f + j * 0.0001f;
        a3_data[j] = 3.0f + j * 0.0001f;
        a4_data[j] = 4.0f + j * 0.0001f;
    }

    a_offset1 = a1_data;
    a_offset2 = a2_data;
    a_offset3 = a3_data;
    a_offset4 = a4_data;
    b_offset = b_data;

    a1 = a2 = a3 = a4 = a5 = a6 = a7 = a8 = 0.0f;
}