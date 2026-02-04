#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
uint8_t *top;
uint8_t *filtered_top;

static uint8_t top_buffer[64];
static uint8_t filtered_top_buffer[64];

void init_vars() {
    top = top_buffer;
    filtered_top = filtered_top_buffer;
    for (int j = 0; j < 64; j++) {
        top[j] = rand() & 0xFF;
    }
    top[-1] = rand() & 0xFF;
}