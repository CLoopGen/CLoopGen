#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef int integer;

float *out;
float *in;
integer len;
int i;
float coeff;

void init_vars() {
    len = 65536 * 4;  // ~1MB for float arrays (each float is 4 bytes)
    in = (float *)aligned_alloc(32, len * sizeof(float));
    out = (float *)aligned_alloc(32, len * sizeof(float));

    for (int j = 0; j < len; j++) {
        in[j] = (float)(j % 1000) / 100.0f;
    }

    coeff = 1.5f;
    i = 0;
}