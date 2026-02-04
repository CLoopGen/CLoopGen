#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};

int i;
uint8_t *left;
int size_max_y;
uint32_t pix;

void init_vars() {
    size_max_y = 67108864; // ~64MB, ensures loop runs approx 0.01s on modern CPU
    left = aligned_alloc(4, size_max_y);
    if (!left) exit(1);
    pix = 0xdeadbeef;
}

__attribute__((destructor))
static void cleanup() {
    free(left);
}