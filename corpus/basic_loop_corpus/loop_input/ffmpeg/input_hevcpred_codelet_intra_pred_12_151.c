#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};

int i;
int size;
uint16_t *top;
uint64_t pix;

void init_vars() {
    pix = 0x123456789ABCDEF0ULL;
    size = (1 << 24); // 16M elements, ~32MB of data since uint16_t
    top = aligned_alloc(64, size * sizeof(uint16_t));
    if (!top) {
        exit(1);
    }
}