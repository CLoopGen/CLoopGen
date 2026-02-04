#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

uint16_t *dst;
uint16_t *src;
int w;
long i;
unsigned long pw_lsb;
unsigned long pw_msb;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime estimate
    const size_t num_elements = data_size / sizeof(uint16_t);

    // Allocate aligned memory to allow safe casting to long
    src = aligned_alloc(sizeof(long), data_size);
    dst = aligned_alloc(sizeof(long), data_size);

    if (!src || !dst) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize arrays with predictable patterns
    for (size_t j = 0; j < num_elements; ++j) {
        src[j] = (uint16_t)(j & 0xFFFF);
        dst[j] = (uint16_t)((j ^ 0x55AA) & 0xFFFF);
    }

    // Set loop boundary: ensure we don't overrun in the loop
    // Loop steps by sizeof(long)/2, and requires room for a full long at end
    w = (int)(num_elements - sizeof(long)/2);

    // Initialize pw_lsb and pw_msb to meaningful bit masks
    pw_lsb = 0x5555555555555555UL; // Alternating bits starting with 1
    pw_msb = 0xAAAAAAAAAAAAAAAAUL; // Alternating bits starting with 0
}

// Ensure symbols are defined even if not used elsewhere
static void __attribute__((constructor)) initialize() {
    init_vars();
}