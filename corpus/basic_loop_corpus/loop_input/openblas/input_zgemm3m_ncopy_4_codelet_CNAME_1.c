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

static float *a_array1;
static float *a_array2;
static float *b_array;

void init_vars() {
    const BLASLONG array_size = 67108864; // ~256 MB of floats (67M elements * 4 bytes)
    m = array_size / 2;

    a_array1 = (float*)calloc(array_size, sizeof(float));
    a_array2 = (float*)calloc(array_size, sizeof(float));
    b_array = (float*)calloc(array_size, sizeof(float));

    a_offset1 = a_array1;
    a_offset2 = a_array2;
    b_offset = b_array;

    for (BLASLONG j = 0; j < array_size; j++) {
        a_array1[j] = 1.0f;
        a_array2[j] = 2.0f;
    }
}