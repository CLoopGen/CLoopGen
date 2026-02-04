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
    // Variant 1: Strided memory access with stride of 1 (conceptually same but accessed in reverse order)
    for (n = (16 / sizeof(unsigned long)) - 1; n != (size_t)-1; --n)
        tmp2.data[n] ^= iv2.data[n];
}
