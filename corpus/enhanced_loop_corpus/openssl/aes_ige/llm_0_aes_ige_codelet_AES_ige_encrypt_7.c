#include <stdio.h>

#include <inttypes.h>

typedef struct {
    unsigned long data[2];
} aes_block_t __attribute__((aligned(1)));

extern size_t n;
extern aes_block_t tmp;
extern aes_block_t iv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t outer_n;
    for (outer_n = 0; outer_n < 1; ++outer_n)
        for (n = 0; n < (16 / sizeof(unsigned long)); ++n)
            tmp.data[n] ^= iv.data[n];
}
