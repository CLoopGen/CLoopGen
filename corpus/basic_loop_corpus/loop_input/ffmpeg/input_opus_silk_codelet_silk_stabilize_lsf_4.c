#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t nlsf[16];
int order = 16;
uint16_t min_delta[17];
int i;

void init_vars() {
    for (int j = 0; j < 16; j++) {
        nlsf[j] = (int16_t)(j * 2000);
    }
    for (int j = 0; j < 17; j++) {
        min_delta[j] = 100;
    }
}