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
    for (n = 0; n < (32 / sizeof(unsigned long)); ++n) {
        size_t idx = n % (16 / sizeof(unsigned long));
        tmp2.data[idx] ^= iv2.data[idx];
        tmp2.data[idx] ^= (tmp2.data[idx] >> 16);
    }
}
