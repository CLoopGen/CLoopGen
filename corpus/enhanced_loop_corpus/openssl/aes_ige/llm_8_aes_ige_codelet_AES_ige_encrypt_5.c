#include <stdio.h>

#include <inttypes.h>

typedef struct {
    unsigned long data[2];
} aes_block_t __attribute__((aligned(1)));

extern size_t n;
extern aes_block_t *ivp;
extern aes_block_t *outp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = 0; n < (16 / sizeof(unsigned long)); ++n) {
        outp->data[n] ^= ivp->data[n];
        outp->data[n] += 1;
        outp->data[n] *= 2;
    }
}
