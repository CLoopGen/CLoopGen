#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};

int i;
int size = 67108864; // 64MB, leads to ~0.01 sec on modern CPUs
uint8_t *top;
uint32_t pix = 0xDEADBEEF;

void init_vars() {
    top = aligned_alloc(4, size * 2);
    if (!top) {
        exit(1);
    }
}