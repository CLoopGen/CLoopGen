#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef int integer;

int32_t *out;
int32_t *in;
integer len;
int i;
int64_t coeff;

void init_vars() {
    len = 16777216; // ~64 MB input (16M elements * 4 bytes per int32_t)

    in = (int32_t*)aligned_alloc(32, len * sizeof(int32_t));
    out = (int32_t*)aligned_alloc(32, len * sizeof(int32_t));

    if (!in || !out) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (i = 0; i < len; i++) {
        in[i] = rand() % 1000 - 500; // Random values between -500 and 499
    }

    coeff = 32768; // Example coefficient: represents a fixed-point multiplier
}