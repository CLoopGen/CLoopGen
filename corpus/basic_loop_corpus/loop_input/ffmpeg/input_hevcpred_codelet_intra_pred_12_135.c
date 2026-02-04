#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int size;
ptrdiff_t stride;
uint16_t *src;
uint16_t *left;

static uint16_t *src_buffer;
static uint16_t *left_buffer;

void init_vars() {
    size = 65536; 
    stride = 1;
    i = 0;

    src_buffer = aligned_alloc(32, (size + 1) * sizeof(uint16_t));
    left_buffer = aligned_alloc(32, size * sizeof(uint16_t));

    if (!src_buffer || !left_buffer) {
        exit(1);
    }

    src = src_buffer + 1;
    left = left_buffer;

    for (int idx = 0; idx < size + 1; ++idx) {
        (src - 1)[idx] = (uint16_t)(idx & 0xFFFF);
    }
    for (int idx = 0; idx < size; ++idx) {
        left[idx] = 0;
    }
}