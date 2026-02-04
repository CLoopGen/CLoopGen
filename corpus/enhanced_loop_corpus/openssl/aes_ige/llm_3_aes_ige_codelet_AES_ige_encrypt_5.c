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
    // Variant 2: Strided memory access with stride of 1 (conceptually same order, but expressed differently)
    // Here we simulate a strided pattern that could be extended; using index doubling and halving to maintain bounds
    const size_t num_elements = 16 / sizeof(unsigned long);
    size_t step = 1;
    size_t n;
    for (n = 0; n < num_elements; n += step)
        outp->data[n] ^= ivp->data[n];
}
