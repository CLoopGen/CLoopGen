#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint16_t *top;
uint16_t *left;
int i;
uint16_t v[46];

static uint16_t top_data[18];
static uint16_t left_data[18];

void init_vars() {
    const size_t data_size = 1 << 20;
    top = top_data;
    left = left_data;

    for (size_t idx = 0; idx < 18; ++idx) {
        top[idx] = (uint16_t)(idx * 37);
        left[idx] = (uint16_t)(idx * 97);
    }

    for (int j = 0; j < 46; ++j) {
        v[j] = 0;
    }

    i = 0;
}