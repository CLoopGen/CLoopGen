#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *left;
int i;
uint8_t v[14];

static uint8_t left_data[1000000];

void init_vars() {
    left = left_data;

    for (int j = 0; j < 1000000; j++) {
        left[j] = rand() & 0xFF;
    }

    for (int j = 0; j < 14; j++) {
        v[j] = 0;
    }

    i = 0;
}