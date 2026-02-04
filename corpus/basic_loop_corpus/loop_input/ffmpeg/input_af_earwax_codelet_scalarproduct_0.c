#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int8_t filt[64];
int16_t *in;
int32_t sample;
int16_t j;

void init_vars() {
    in = (int16_t*)aligned_alloc(32, 64 * sizeof(int16_t));
    if (!in) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < 64; i++) {
        filt[i] = (int8_t)(i & 0x7F); 
        in[i] = (int16_t)(i * 2);
    }
    sample = 0;
    j = 0;
}