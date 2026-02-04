#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t nlsf[16];
int order = 15;
uint16_t min_delta[17];
int pass;
int i;

void init_vars() {
    order = 15;
    for (int idx = 0; idx < 16; idx++) {
        nlsf[idx] = (int16_t)(idx * 2000);
    }
    for (int idx = 0; idx < 17; idx++) {
        min_delta[idx] = (uint16_t)(100 + (idx * 37));
    }
}