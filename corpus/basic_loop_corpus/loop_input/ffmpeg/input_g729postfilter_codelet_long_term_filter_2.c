#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int subframe_size = 192;
int i;
int16_t shift = 4;

int16_t *residual;
int16_t sig_scaled[192];

void init_vars() {
    residual = (int16_t*)aligned_alloc(32, (subframe_size + 143 + 8 + 1) * sizeof(int16_t));
    if (!residual) exit(1);

    for (int j = 0; j < subframe_size + 143 + 8 + 1; j++) {
        residual[j] = (int16_t)(j % 32768);
    }

    for (int j = 0; j < 192; j++) {
        sig_scaled[j] = 0;
    }
}

void loop();