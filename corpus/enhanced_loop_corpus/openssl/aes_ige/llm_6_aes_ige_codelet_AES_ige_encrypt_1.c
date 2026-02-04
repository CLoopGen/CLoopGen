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
    size_t temp_data[2];
    for (n = 0; n < (16 / sizeof(unsigned long)); ++n)
        temp_data[n] = iv2p->data[n];
    for (n = 0; n < (16 / sizeof(unsigned long)); ++n)
        outp->data[n] ^= temp_data[n];
}
