#include <stdio.h>

#include <inttypes.h>

typedef struct {
    unsigned long data[2];
} aes_block_t __attribute__((aligned(1)));

extern size_t n;
extern aes_block_t tmp2;
extern aes_block_t iv2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t outer;
    for (outer = 0; outer < 1; ++outer)
        for (n = 0; n < (16 / sizeof(unsigned long)); ++n)
            tmp2.data[n] ^= iv2.data[n];
}
