#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
uint8_t *left;

static uint8_t left_data[64];

void init_vars() {
    left = left_data;
    for (int j = 0; j < 64; j++) {
        left[j] = rand() & 0xFF;
    }
}