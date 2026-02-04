#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t impulse_r[60];
int16_t temp_corr[60];
int i;

void init_vars() {
    for (int j = 0; j < 60; j++) {
        impulse_r[j] = (int16_t)(j * 2 + 1);
        temp_corr[j] = 0;
    }
    i = 0;
}