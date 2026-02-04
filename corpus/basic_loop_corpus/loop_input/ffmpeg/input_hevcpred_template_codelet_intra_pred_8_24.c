#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
uint8_t *top;
uint8_t *filtered_top;

static uint8_t top_data[64];
static uint8_t filtered_top_data[64];

void init_vars() {
    top = top_data;
    filtered_top = filtered_top_data;

    for (int idx = 0; idx < 64; idx++) {
        top[idx] = rand() & 0xFF;
    }
}