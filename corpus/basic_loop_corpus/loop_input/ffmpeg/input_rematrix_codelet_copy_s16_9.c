#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;

int16_t *out;
int16_t *in;
integer len;
int i;
int coeff;

void init_vars() {
    len = 8000000;  // Approximate size for ~0.01 sec runtime (adjustable based on system)

    in = (int16_t*)aligned_alloc(32, len * sizeof(int16_t));
    out = (int16_t*)aligned_alloc(32, len * sizeof(int16_t));

    if (!in || !out) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (integer idx = 0; idx < len; idx++) {
        in[idx] = (int16_t)(idx % 32768);
    }

    coeff = 12345;
    i = 0;
}