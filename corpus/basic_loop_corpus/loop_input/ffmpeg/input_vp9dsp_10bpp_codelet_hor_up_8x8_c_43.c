#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint16_t *left;
int i;
uint16_t v[14];

static uint16_t left_data[1000000]; // ~2MB of data to target 0.01s runtime

void init_vars() {
    for (int j = 0; j < 1000000; j++) {
        left_data[j] = (uint16_t)(j % 500);
    }
    left = left_data;
    i = 0;
    for (int j = 0; j < 14; j++) {
        v[j] = 0;
    }
}