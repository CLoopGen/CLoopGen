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
    // Variant 2: Reverse sequential access — modifies memory access order to descending
    size_t i;
    size_t count = (16 / sizeof(unsigned long));
    for (i = 0; i < count; ++i) {
        size_t idx = count - 1 - i;  // reverse index
        tmp.data[idx] ^= iv.data[idx];
    }
    n = count; // maintain expected side effect on `n` if used externally
}
