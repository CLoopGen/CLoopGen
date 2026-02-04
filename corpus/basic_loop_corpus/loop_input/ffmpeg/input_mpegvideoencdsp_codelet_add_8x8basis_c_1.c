#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t rem[64];
int16_t basis[64];
int scale;
int i;

void init_vars() {
    for (i = 0; i < 64; i++) {
        rem[i] = rand() % 1000;
        basis[i] = rand() % 1000;
    }
    scale = rand() % 100 + 1;
    i = 0;
}