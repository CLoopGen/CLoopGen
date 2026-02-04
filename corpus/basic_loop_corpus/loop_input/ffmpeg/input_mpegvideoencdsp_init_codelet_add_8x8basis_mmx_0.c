#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int x86_reg;

int16_t rem[64];
int16_t basis[64];
int scale;
x86_reg i;

void init_vars() {
    for (x86_reg idx = 0; idx < 64; idx++) {
        rem[idx] = (int16_t)(idx % 32);
        basis[idx] = (int16_t)((idx * 7) % 64);
    }
    scale = 100;
    i = 0;
}