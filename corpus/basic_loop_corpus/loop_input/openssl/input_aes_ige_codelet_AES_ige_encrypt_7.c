#include <stdio.h>
#include <inttypes.h>

typedef struct {
    unsigned long data[2];
} aes_block_t __attribute__((aligned(1)));

size_t n;
aes_block_t tmp;
aes_block_t iv;

void init_vars() {
    // Initialize all values to zero for predictable behavior
    n = 0;
    tmp.data[0] = 0x12345678UL;
    tmp.data[1] = 0xABCDEF01UL;
    iv.data[0] = 0xFEDCBA98UL;
    iv.data[1] = 0x76543210UL;
}