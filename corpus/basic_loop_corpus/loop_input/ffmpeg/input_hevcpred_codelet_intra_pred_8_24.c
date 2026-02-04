#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};

int i;
int size = 65536; // Ensures 2 * size = 131072 bytes are accessed, fitting within allocated buffer
uint8_t *top;
uint32_t pix = 0xCAFEBABE;

void init_vars() {
    top = aligned_alloc(4, 2 * size);
    if (!top) {
        exit(1);
    }
    for (int j = 0; j < 2 * size; j++) {
        top[j] = 0;
    }
}