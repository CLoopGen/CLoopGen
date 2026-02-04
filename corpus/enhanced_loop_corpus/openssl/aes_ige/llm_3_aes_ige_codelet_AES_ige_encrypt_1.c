#include <stdio.h>

#include <inttypes.h>

typedef struct {
    unsigned long data[2];
} aes_block_t __attribute__((aligned(1)));

extern size_t n;
extern aes_block_t *iv2p;
extern aes_block_t *outp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with stride of 1 but reversed order (reverse traversal)
    for (size_t n = (16 / sizeof(unsigned long)) - 1; n != (size_t)-1; --n)
        outp->data[n] ^= iv2p->data[n];
}
