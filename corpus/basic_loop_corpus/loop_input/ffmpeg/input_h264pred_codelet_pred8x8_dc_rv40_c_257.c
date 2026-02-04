#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
ptrdiff_t stride;
int i;
unsigned int dc0;

static uint8_t *src_buffer;

void init_vars() {
    size_t total_size = 1 << 20; // 1MB
    src_buffer = aligned_alloc(32, total_size);
    if (!src_buffer) {
        exit(1);
    }

    stride = 64; 
    src = src_buffer;
    dc0 = 0xdeadbeefU;
    i = 0;
}