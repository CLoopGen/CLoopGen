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
    top = top_buffer + 1;
    filtered_top = filtered_top_buffer;
    
    for (int j = 0; j < 64; j++) {
        top_buffer[j] = rand() & 0xFF;
    }
    for (int j = 0; j < 64; j++) {
        filtered_top_buffer[j] = 0;
    }
    i = 0;
}