#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *coef;
int i;
int16_t tmp[16];

static int16_t coef_data[16];

void init_vars() {
    coef = coef_data;

    for (int j = 0; j < 16; j++) {
        coef[j] = (int16_t)(j * 31);
    }

    for (int j = 0; j < 16; j++) {
        tmp[j] = 0;
    }

    i = 0;
}