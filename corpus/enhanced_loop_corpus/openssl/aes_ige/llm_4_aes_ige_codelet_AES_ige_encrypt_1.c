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
    size_t limit = 16 / sizeof(unsigned long);
    for (n = 0; n < limit; ++n) {
        if (iv2p->data[n] != 0)
            outp->data[n] ^= iv2p->data[n];
    }
}
