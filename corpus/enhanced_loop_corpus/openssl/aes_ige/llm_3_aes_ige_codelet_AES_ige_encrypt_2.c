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
    // Variant 2: Strided memory access with reverse order and stride of 1 (effectively reversed traversal)
    size_t i;
    size_t count = (16 / sizeof(unsigned long));
    for (i = 0; i < count; ++i) {
        size_t idx = count - 1 - i;  // Reverse the access order (strided in decreasing order)
        tmp2.data[idx] = tmp.data[idx] ^ iv.data[idx];
    }
}
