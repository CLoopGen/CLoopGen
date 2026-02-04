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
    size_t i;
    aes_block_t temp = tmp;
    for (i = 0; i < (16 / sizeof(unsigned long)); ++i)
        temp.data[i] ^= iv.data[i];
    tmp = temp;
}
