#include <stdio.h>

#include <inttypes.h>

typedef struct {
    unsigned long data[2];
} aes_block_t __attribute__((aligned(1)));

extern size_t n;
extern aes_block_t *ivp;
extern aes_block_t *outp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    aes_block_t *outp_local = outp;
    aes_block_t *ivp_local = ivp;
    unsigned long *out_data = outp_local->data;
    unsigned long *iv_data = ivp_local->data;
    size_t limit = (16 / sizeof(unsigned long));
    for (n = 0; n < limit; ++n) {
        unsigned long combined = out_data[n] ^ iv_data[n];
        out_data[n] = combined;
    }
}
