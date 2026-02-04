#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef struct {
    unsigned long data[2];
} aes_block_t __attribute__((aligned(1)));

size_t n;
aes_block_t *ivp;
aes_block_t *inp;
aes_block_t *outp;

void init_vars() {
    size_t num_blocks = 65536 / sizeof(aes_block_t);
    ivp = (aes_block_t*)malloc(num_blocks * sizeof(aes_block_t));
    inp = (aes_block_t*)malloc(num_blocks * sizeof(aes_block_t));
    outp = (aes_block_t*)malloc(num_blocks * sizeof(aes_block_t));

    for (size_t i = 0; i < num_blocks; ++i) {
        inp[i].data[0] = i + 1;
        inp[i].data[1] = i + 2;
        ivp[i].data[0] = i + 3;
        ivp[i].data[1] = i + 4;
        outp[i].data[0] = 0;
        outp[i].data[1] = 0;
    }

    n = 0;
}