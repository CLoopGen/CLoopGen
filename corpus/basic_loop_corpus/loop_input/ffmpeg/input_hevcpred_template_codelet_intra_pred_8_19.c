#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};

int i;
int size = 65536; // Ensures loop runs for ~0.01 sec (65536 * 4 bytes = 262144 bytes accessed)
uint8_t *top;
uint32_t pix = 0xCAFEBABE;

void init_vars() {
    top = aligned_alloc(4, (2 * size));
    if (!top) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
}