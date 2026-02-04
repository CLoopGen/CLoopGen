#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};

int i;
int size = 32000000; // ~256MB of data for left array (size * sizeof(uint16_t) * 2)
uint16_t *left;
uint64_t pix = 0x123456789ABCDEF0ULL;

void init_vars() {
    left = aligned_alloc(64, (size + size) * sizeof(uint16_t));
    if (!left) {
        exit(1);
    }
}