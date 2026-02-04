#include <stdio.h>
#include <stdlib.h>

typedef long BLASLONG;

BLASLONG m;
BLASLONG i;
float *a_offset1;
float *b_offset;
float a1;
float a2;

static float *a_array;
static float *b_array;

void init_vars() {
    BLASLONG array_size = 67108864; // ~256MB of float data (each float is 4 bytes)

    m = array_size;

    a_array = (float*)calloc(array_size * 2, sizeof(float));
    b_array = (float*)calloc(array_size, sizeof(float));

    if (!a_array || !b_array) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    a_offset1 = a_array;
    b_offset = b_array;

    for (BLASLONG j = 0; j < array_size * 2; j++) {
        a_array[j] = 1.0f;
    }
}