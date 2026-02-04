#include <stdio.h>

#include <inttypes.h>

extern unsigned char *rsa_in;
extern size_t rsa_inlen;
extern size_t i;
extern unsigned char ctmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access (process every 2nd element)
    for (i = 0; i < rsa_inlen / 4; i++) {
        size_t forward_index = 2 * i;
        size_t backward_index = rsa_inlen - 1 - 2 * i;
        ctmp = rsa_in[forward_index];
        rsa_in[forward_index] = rsa_in[backward_index];
        rsa_in[backward_index] = ctmp;
    }
}
