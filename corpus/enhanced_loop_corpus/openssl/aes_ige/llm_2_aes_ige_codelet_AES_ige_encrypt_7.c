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
    // Variant 1: Strided memory access with stride of 2, unrolled by factor 2
    // Access pattern: data[0], data[2], ... (if applicable), but since size is small (likely 2 elements), we simulate strided logic safely
    size_t limit = (16 / sizeof(unsigned long));
    for (n = 0; n < limit; n += 2) {
        if (n < limit)
            tmp.data[n] ^= iv.data[n];
        if ((n + 1) < limit)
            tmp.data[n + 1] ^= iv.data[n + 1];
    }
}
