#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

typedef int integer;

int32_t *out;
int32_t *in1;
int32_t *in2;
integer len;
int i;
int64_t coeff1;
int64_t coeff2;

void init_vars() {
    len = 16777216; // ~64 MB of input data (16M elements * 4 bytes * 4 arrays)

    in1 = (int32_t*)aligned_alloc(32, len * sizeof(int32_t));
    in2 = (int32_t*)aligned_alloc(32, len * sizeof(int32_t));
    out = (int32_t*)aligned_alloc(32, len * sizeof(int32_t));

    for (int j = 0; j < len; j++) {
        in1[j] = rand() % 1000 - 500;
        in2[j] = rand() % 1000 - 500;
    }

    coeff1 = 32768;
    coeff2 = 16384;
    i = 0;
}