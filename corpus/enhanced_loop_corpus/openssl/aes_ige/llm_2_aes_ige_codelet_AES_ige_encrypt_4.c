#include <stdio.h>

#include <inttypes.h>

typedef struct {
    unsigned long data[2];
} aes_block_t __attribute__((aligned(1)));

extern size_t n;
extern aes_block_t *iv2p;
extern aes_block_t tmp;
extern aes_block_t *inp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with reversed traversal order
    for (n = (16 / sizeof(unsigned long)) - 1; n != (size_t)-1; --n)
        tmp.data[n] = inp->data[n] ^ iv2p->data[n];
}
