#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};

int i;
int size = 65536; // ~512KB of data (size used in indexing top array)
int top_right_size = 64;
uint16_t *top;

uint64_t pix = 0xCAFEBABEDEADBEEFULL;

void init_vars() {
    top = aligned_alloc(64, sizeof(uint16_t) * (size + top_right_size + 256));
    if (!top) {
        exit(1);
    }
    // Ensure the memory region accessed by loop is valid:
    // Loop accesses: top + size + top_right_size + i, for i up to size - top_right_size
    // Max index: size + top_right_size + (size - top_right_size) = 2*size
    // So we need at least 2*size elements allocated to prevent overflow.
    // Reallocate with sufficient size.
    free(top);
    top = aligned_alloc(64, sizeof(uint16_t) * (2 * size + 128));
    if (!top) {
        exit(1);
    }
}