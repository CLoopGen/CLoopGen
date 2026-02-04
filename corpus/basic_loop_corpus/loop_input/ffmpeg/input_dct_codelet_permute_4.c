#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t dst[64];
int16_t src[64];
int i;

void init_vars() {
    for (int j = 0; j < 64; j++) {
        src[j] = (int16_t)(j * 2);
        dst[j] = 0;
    }
    i = 0;
}