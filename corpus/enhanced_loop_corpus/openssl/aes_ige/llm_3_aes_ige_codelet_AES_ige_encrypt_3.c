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
    // Variant 2: Consecutive access using pointer arithmetic to iterate through data arrays
    unsigned long *p_tmp = tmp2.data;
    unsigned long *p_iv = iv2.data;
    size_t count = 16 / sizeof(unsigned long);
    for (n = 0; n < count; ++n)
        *(p_tmp + n) ^= *(p_iv + n);
}
