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
    aes_block_t local_tmp2 = tmp2;
    for (n = 0; n < (16 / sizeof(unsigned long)); ++n) {
        local_tmp2.data[n] = tmp.data[n] ^ iv.data[n];
    }
    tmp2 = local_tmp2;
}
