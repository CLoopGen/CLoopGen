#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
uint16_t *top;
uint16_t *filtered_top;

static uint16_t top_buffer[64];
static uint16_t filtered_top_buffer[64];

void init_vars() {
    top = top_buffer;
    filtered_top = filtered_top_buffer;

    for (int idx = 0; idx < 64; idx++) {
        top[idx] = (uint16_t)(idx * 12345U + 17);
    }
}

__attribute__((constructor))
static void constructor_init() {
    init_vars();
}