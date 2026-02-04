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
    size = 65536;  // Ensures 2 * size = 131072 elements, total data size = 131072 * 2 = 262144 bytes (~256KB), safe for alignment and cache effects
    pix = 0xCAFEBABEDEADBEEFULL;

    // Allocate aligned memory to ensure that unaligned_64 access (on 64-bit boundary) is safe even when casting from uint16_t*
    // We need 2*size uint16_t's -> 2*size*2 = 4*size bytes. Also ensure allocation allows 8-byte alignment for the union.
    top = (uint16_t*)aligned_alloc(8, 4 * size);
    if (!top) {
        exit(1);
    }

    // Initialize all memory to zero
    for (int j = 0; j < 2 * size; j++) {
        top[j] = 0;
    }
}

__attribute__((destructor))
static void cleanup() {
    free(top);
}