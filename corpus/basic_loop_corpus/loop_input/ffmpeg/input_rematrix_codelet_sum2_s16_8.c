#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;

int16_t *out;
int16_t *in1;
int16_t *in2;
integer len;
int i;
int coeff1;
int coeff2;

void init_vars() {
    len = 4000000; // Approximate size to run loop for ~0.01 seconds

    in1 = (int16_t*)aligned_alloc(32, len * sizeof(int16_t));
    in2 = (int16_t*)aligned_alloc(32, len * sizeof(int16_t));
    out = (int16_t*)aligned_alloc(32, len * sizeof(int16_t));

    for (i = 0; i < len; i++) {
        in1[i] = (int16_t)(i & 0x7FFF);
        in2[i] = (int16_t)((i * 3) & 0x7FFF);
    }

    coeff1 = 15000;
    coeff2 = 20000;
}