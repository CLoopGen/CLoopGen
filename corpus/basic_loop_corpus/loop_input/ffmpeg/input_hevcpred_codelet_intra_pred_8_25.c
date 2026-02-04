#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};

int i;
int size = 65536; 
uint8_t *left;
uint32_t pix = 0x12345678;

void init_vars() {
    left = aligned_alloc(16, 2 * size);
    if (!left) {
        exit(1);
    }
}