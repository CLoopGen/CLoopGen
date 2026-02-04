#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int order;
int k;
int32_t lpc32[16];
int16_t lpc[16];

void init_vars() {
    order = 16;

    for (int i = 0; i < 16; i++) {
        lpc32[i] = (int32_t)(i * 1000);
        lpc[i] = 0;
    }
}