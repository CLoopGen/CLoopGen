#include <stdio.h>

#include <inttypes.h>

typedef size_t size_t_aX __attribute__((aligned(1)));

extern size_t n;
extern size_t_aX *out_t;
extern size_t_aX *iv_t;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (n = 0; n < 16 / sizeof(size_t); n += 2) {
        if (n + 1 < 16 / sizeof(size_t)) {
            out_t[n] ^= iv_t[n];
            out_t[n + 1] ^= iv_t[n + 1];
        } else {
            out_t[n] ^= iv_t[n];
        }
    }
}
