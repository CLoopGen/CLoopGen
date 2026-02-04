#include <stdio.h>

#include <inttypes.h>

typedef struct {
    unsigned long data[2];
} aes_block_t __attribute__((aligned(1)));

extern size_t n;
extern aes_block_t tmp;
extern aes_block_t tmp2;
extern aes_block_t iv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access using pointer arithmetic
    unsigned long *tmp_ptr = tmp.data;
    unsigned long *iv_ptr = iv.data;
    unsigned long *tmp2_ptr = tmp2.data;
    size_t i;
    for (i = 0; i < (16 / sizeof(unsigned long)); ++i) {
        *tmp2_ptr++ = *tmp_ptr++ ^ *iv_ptr++;
    }
}
