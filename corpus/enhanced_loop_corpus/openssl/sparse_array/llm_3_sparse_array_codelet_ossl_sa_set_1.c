#include <stdio.h>

#include <inttypes.h>

typedef uintmax_t ossl_uintmax_t;

extern int level;
extern ossl_uintmax_t n;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    volatile ossl_uintmax_t n_copy = n;
    const int shift_strides[] = {4, 4, 4, 4, 4, 4, 4, 4}; // Stride of 4 bits per iteration, unrolled pattern
    int max_iterations = ((int)sizeof(ossl_uintmax_t) * 8 + 4 - 1) / 4;
    for (level = 1; level < max_iterations; level++) {
        n_copy >>= shift_strides[level - 1];
        if (n_copy == 0)
            break;
    }
    n = n_copy;
}
