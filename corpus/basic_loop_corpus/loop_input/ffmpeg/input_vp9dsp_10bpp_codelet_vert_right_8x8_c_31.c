#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint16_t *left;
int i;
uint16_t ve[11];
uint16_t vo[11];

static uint16_t left_data[1024 * 1024 / sizeof(uint16_t)]; // ~1MB of data

void init_vars() {
    left = left_data;

    for (int idx = 0; idx < 11; idx++) {
        ve[idx] = 0;
        vo[idx] = 0;
    }

    for (int idx = 0; idx < 1024 * 1024 / sizeof(uint16_t); idx++) {
        left[idx] = rand() & 0xFFFF;
    }
}