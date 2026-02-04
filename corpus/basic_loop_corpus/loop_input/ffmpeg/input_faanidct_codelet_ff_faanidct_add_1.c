#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float FLOAT;

FLOAT prescale[64];
int16_t block[64];
FLOAT temp[64];
int i;

void init_vars() {
    for (int idx = 0; idx < 64; idx++) {
        prescale[idx] = 1.5f + idx * 0.1f;
        block[idx] = (int16_t)(idx * 2 - 64);
        temp[idx] = 0.0f;
    }
    i = 0;
}