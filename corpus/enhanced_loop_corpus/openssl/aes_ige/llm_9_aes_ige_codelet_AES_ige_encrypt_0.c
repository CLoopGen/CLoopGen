#include <stdio.h>

#include <inttypes.h>

typedef struct {
    unsigned long data[2];
} aes_block_t __attribute__((aligned(1)));

extern size_t n;
extern aes_block_t *ivp;
extern aes_block_t *inp;
extern aes_block_t *outp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = 0; n < 2 * (16 / sizeof(unsigned long)); ++n) {
        size_t idx = n / 2;
        if (n % 2 == 0)
            outp->data[idx] = inp->data[idx] ^ ivp->data[idx];
        else
            outp->data[idx] = (inp->data[idx] ^ ivp->data[idx]) + (outp->data[idx] >> 1);
    }
}
