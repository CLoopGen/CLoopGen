#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};

int i;
int size = 65536;  // 64k iterations * 4 bytes = 256KB of data written
uint8_t *left;
uint32_t pix = 0xdeadbeef;

void init_vars() {
    left = aligned_alloc(4, (size_t)(2 * size));
    if (!left) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
}