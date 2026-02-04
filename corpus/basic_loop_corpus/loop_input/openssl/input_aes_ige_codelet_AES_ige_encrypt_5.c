#include <stdio.h>
#include <inttypes.h>

typedef struct {
    unsigned long data[2];
} aes_block_t __attribute__((aligned(1)));

size_t n;
aes_block_t *ivp;
aes_block_t *outp;

aes_block_t iv_buffer;
aes_block_t out_buffer;

void init_vars() {
    n = 0;
    ivp = &iv_buffer;
    outp = &out_buffer;

    for (int i = 0; i < 2; ++i) {
        iv_buffer.data[i] = 0xABCDEF012345678ULL + i;
        out_buffer.data[i] = 0xFEDCBA987654321ULL + i;
    }
}