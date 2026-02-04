#include <stdio.h>
#include <stdlib.h>

typedef long BLASLONG;

BLASLONG m;
BLASLONG i;

float *a_offset1;
float *a_offset2;
float *a_offset3;
float *a_offset4;
float *a_offset5;
float *a_offset6;
float *a_offset7;
float *a_offset8;
float *b_offset;

float a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16;

void init_vars() {
    const BLASLONG vector_length = 8;
    const BLASLONG total_elements_a = 2 * vector_length; 
    const BLASLONG total_elements_b = 8;

    const size_t data_size_bytes = 1 << 24; 
    const size_t element_size = sizeof(float);
    const BLASLONG n = data_size_bytes / (element_size * total_elements_a);

    m = n;

    float *ptr_a = (float *)aligned_alloc(32, sizeof(float) * total_elements_a * n);
    float *ptr_b = (float *)aligned_alloc(32, sizeof(float) * total_elements_b * n);

    a_offset1 = ptr_a + 0*n;
    a_offset2 = ptr_a + 2*n;
    a_offset3 = ptr_a + 4*n;
    a_offset4 = ptr_a + 6*n;
    a_offset5 = ptr_a + 8*n;
    a_offset6 = ptr_a + 10*n;
    a_offset7 = ptr_a + 12*n;
    a_offset8 = ptr_a + 14*n;
    b_offset = ptr_b;

    for (BLASLONG i = 0; i < total_elements_a * n; i++) {
        ptr_a[i] = (float)(i % 100) / 10.0f;
    }
    for (BLASLONG i = 0; i < total_elements_b * n; i++) {
        ptr_b[i] = 0.0f;
    }
}