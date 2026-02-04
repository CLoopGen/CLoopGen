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
    // Variant 1: Consecutive memory access using pointer arithmetic
    unsigned long *out_data = outp->data;
    unsigned long *iv2_data = iv2p->data;
    size_t i;
    for (i = 0; i < (16 / sizeof(unsigned long)); ++i) {
        *(out_data + i) ^= *(iv2_data + i);
    }
}
