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
    // Variant 2: Strided memory access with reverse traversal (stride of 1, but backwards)
    for (n = (16 / sizeof(unsigned long)) - 1; n != (size_t)-1; --n) {
        outp->data[n] = inp->data[n] ^ ivp->data[n];
    }
}
