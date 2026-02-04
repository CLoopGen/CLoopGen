#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *out;
int16_t *in1;
int16_t *in2;
int length;
int shift;

void init_vars() {
    length = 32 * 1024 * 1024 / sizeof(int16_t); // ~64MB of total data, ~21.3MB per array
    shift = 1; // reasonable default shift value

    in1 = (int16_t *)aligned_alloc(32, length * sizeof(int16_t));
    in2 = (int16_t *)aligned_alloc(32, length * sizeof(int16_t));
    out = (int16_t *)aligned_alloc(32, length * sizeof(int16_t));

    for (int i = 0; i < length; i++) {
        in1[i] = (int16_t)(i & 0xFFFF);
        in2[i] = (int16_t)((i * 3) & 0xFFFF);
        out[i] = 0;
    }
}