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
    top_right_size = 0;
    pix = 0xDEADBEEF;
    top = aligned_alloc(16, 256 * 1024 * 1024);
    if (!top) exit(1);
}

void loop();