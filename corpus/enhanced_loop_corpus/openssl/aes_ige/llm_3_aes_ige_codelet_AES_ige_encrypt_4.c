#include <stdio.h>

#include <inttypes.h>

typedef struct {
    unsigned long data[2];
} aes_block_t __attribute__((aligned(1)));

extern size_t n;
extern aes_block_t *iv2p;
extern aes_block_t tmp;
extern aes_block_t *inp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with stride of 2, unrolling the loop to access every other element
    size_t step = 2;
    size_t iter_count = (16 / sizeof(unsigned long) + step - 1) / step;
    for (n = 0; n < iter_count; ++n) {
        size_t idx = n * step;
        if (idx < (16 / sizeof(unsigned long)))
            tmp.data[idx] = inp->data[idx] ^ iv2p->data[idx];
        idx++;
        if (idx < (16 / sizeof(unsigned long)))
            tmp.data[idx] = inp->data[idx] ^ iv2p->data[idx];
    }
}
