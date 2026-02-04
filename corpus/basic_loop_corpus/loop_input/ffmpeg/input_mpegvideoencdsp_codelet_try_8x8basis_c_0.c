#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t rem[64];
int16_t weight[64];
int16_t basis[64];
int scale;
int i;
unsigned int sum;

void init_vars() {
    for (int idx = 0; idx < 64; idx++) {
        rem[idx] = (int16_t)(idx * 37);
        weight[idx] = (int16_t)(idx * 13 + 1);
        basis[idx] = (int16_t)(idx * 29 - 1000);
    }
    scale = 50;
    i = 0;
    sum = 0;
}