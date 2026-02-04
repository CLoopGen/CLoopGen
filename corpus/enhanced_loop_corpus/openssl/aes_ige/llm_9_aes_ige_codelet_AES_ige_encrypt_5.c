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
    for (n = 0; n < (32 / sizeof(unsigned long)); ++n) {
        size_t index = n % (16 / sizeof(unsigned long));
        outp->data[index] ^= ivp->data[index] ^ (outp->data[index] >> 1);
    }
}
