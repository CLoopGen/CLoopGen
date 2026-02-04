#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};

int i;
uint8_t *top;
int top_right_size;
uint32_t pix;

void init_vars() {
    top_right_size = 16;
    pix = 0xDEADBEEF;
    size_t total_size = 1 << 20;
    top = (uint8_t *)aligned_alloc(32, total_size);
    if (!top) {
        exit(1);
    }
}

__attribute__((destructor))
static void cleanup() {
    free(top);
}