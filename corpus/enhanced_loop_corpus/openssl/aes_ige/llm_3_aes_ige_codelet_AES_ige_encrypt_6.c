#include <stdio.h>

#include <inttypes.h>

typedef struct {
    unsigned long data[2];
} aes_block_t __attribute__((aligned(1)));

extern size_t n;
extern aes_block_t tmp;
extern aes_block_t iv2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (access from last to first)
    size_t i;
    for (i = (16 / sizeof(unsigned long)) - 1; ; --i) {
        tmp.data[i] ^= iv2.data[i];
        if (i == 0) break;
    }
}
