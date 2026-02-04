#include <stdio.h>

#include <inttypes.h>

typedef struct {
    unsigned long data[2];
} aes_block_t __attribute__((aligned(1)));

extern size_t n;
extern aes_block_t tmp2;
extern aes_block_t iv2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t i, j;
    const size_t factor_a = 2;
    const size_t factor_b = (16 / sizeof(unsigned long)) / 2; // Assuming 16/sizeof(ulong) is even
    for (i = 0; i < factor_a; ++i)
        for (j = 0; j < factor_b; ++j) {
            n = i * factor_b + j;
            tmp2.data[n] ^= iv2.data[n];
        }
}
