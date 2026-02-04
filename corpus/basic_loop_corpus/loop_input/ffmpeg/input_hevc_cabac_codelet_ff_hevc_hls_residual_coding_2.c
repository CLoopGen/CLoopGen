#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *coeffs;
int i;

static int16_t coeffs_buffer[16];

void init_vars() {
    coeffs = coeffs_buffer;
    for (i = 0; i < 16; i++) {
        coeffs[i] = (int16_t)(i * 2 + 1);
    }
}