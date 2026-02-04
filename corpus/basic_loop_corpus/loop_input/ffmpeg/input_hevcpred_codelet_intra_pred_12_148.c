#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};

int i;
int size = 32768; // Ensures ~131072 bytes written (32768/4 * 16), approximates desired runtime
uint16_t *left;

uint64_t pix = 0xCAFEBABEDEADBEEFULL;

void init_vars() {
    left = aligned_alloc(64, sizeof(uint16_t) * (size + size + 16)); // Allocate extra for safety
    if (!left) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    for (int j = 0; j < (size + size + 16); ++j) {
        left[j] = j & 0xFFFF;
    }
}