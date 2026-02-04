#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *coef;
int i;
int16_t tmp[64];

void init_vars() {
    coef = (int16_t*)calloc(64, sizeof(int16_t));
    if (!coef) {
        exit(1);
    }
    for (int idx = 0; idx < 64; idx++) {
        coef[idx] = (int16_t)(idx * idx % 32768);
    }
}

void loop();