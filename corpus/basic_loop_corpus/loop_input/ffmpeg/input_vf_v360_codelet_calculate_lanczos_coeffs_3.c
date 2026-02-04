#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *coeffs;
float sum;

static float coeffs_buffer[4];

void init_vars() {
    coeffs = coeffs_buffer;
    sum = 2.0f; 

    for (int i = 0; i < 4; i++) {
        coeffs[i] = (float)(i + 1) * 4.0f;
    }
}