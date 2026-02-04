#include <stdio.h>

#include <inttypes.h>

typedef struct {
    unsigned long data[2];
} aes_block_t __attribute__((aligned(1)));

extern size_t n;
extern aes_block_t *iv2p;
extern aes_block_t *outp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    aes_block_t *out_copy = outp;
    for (n = 0; n < (16 / sizeof(unsigned long)); ++n) {
        outp->data[n] ^= iv2p->data[n];
        out_copy->data[n] ^= outp->data[n]; // Introduce WAW and WAR hazard artificially
        outp->data[n] = out_copy->data[n] ^ iv2p->data[n]; // Redundant update, creates loop-carried WAW
    }
}
