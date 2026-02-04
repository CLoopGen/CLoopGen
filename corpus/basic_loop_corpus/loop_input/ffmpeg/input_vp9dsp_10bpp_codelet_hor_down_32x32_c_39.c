#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint16_t *top;
uint16_t *left;
int i;
uint16_t v[94];

#define DATA_SIZE (1 << 20)

static uint16_t top_data[DATA_SIZE];
static uint16_t left_data[DATA_SIZE];

void init_vars() {
    top = top_data + 1;
    left = left_data + 1;

    for (int idx = 0; idx < DATA_SIZE; ++idx) {
        top_data[idx] = (uint16_t)(idx * idx + 31);
        left_data[idx] = (uint16_t)(idx * idx + 73);
    }

    for (int idx = 0; idx < 94; ++idx) {
        v[idx] = 0;
    }
}