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
    for (int j = 0; j < 64; j++) {
        rem[j] = (int16_t)(j * 2);
        basis[j] = (int16_t)(j + 1);
    }
    scale = 50;
    i = 0;
}