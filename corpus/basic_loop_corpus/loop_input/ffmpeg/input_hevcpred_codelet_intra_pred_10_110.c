#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};

int i;
int size = 32768; // Ensures 2 * size = 65536, and loop processes 4 elements per iteration -> 16384 iterations
uint16_t *top;
uint64_t pix = 0x123456789ABCDEF0ULL;

void init_vars() {
    top = aligned_alloc(8, sizeof(uint16_t) * (2 * size));
    if (!top) {
        exit(1);
    }
}