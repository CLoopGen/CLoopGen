#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};

int i;
int size = 65536; // Ensures 2 * size = 131072 bytes are accessed, aligned to 4-byte steps
uint8_t *left;
uint32_t pix = 0xdeadbeef;

void init_vars() {
    left = (uint8_t*)aligned_alloc(4, 2 * size);
    if (!left) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
}