#include <stdio.h>

#include <inttypes.h>

typedef struct {
    unsigned long data[2];
} aes_block_t __attribute__((aligned(1)));

extern size_t n;
extern aes_block_t tmp;
extern aes_block_t iv2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, accessing even indices only
    for (n = 0; n < (16 / sizeof(unsigned long)); n += 2) {
        if (n < (16 / sizeof(unsigned long)))
            tmp.data[n] ^= iv2.data[n];
    }
    // Handle potential odd-sized array by checking bounds
    if ((16 / sizeof(unsigned long)) % 2 == 1) {
        size_t idx = (16 / sizeof(unsigned long)) - 1;
        tmp.data[idx] ^= iv2.data[idx];
    }
}
