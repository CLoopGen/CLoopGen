#include <stdio.h>

#include <inttypes.h>

typedef size_t size_t_aX __attribute__((aligned(1)));

extern size_t n;
extern size_t_aX *out_t;
extern size_t_aX *iv_t;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access
    size_t limit = 16 / sizeof(size_t);
    for (n = 0; n < limit; n++) {
        size_t idx = limit - 1 - n;  // Reverse indexing
        out_t[idx] ^= iv_t[idx];
    }
}
