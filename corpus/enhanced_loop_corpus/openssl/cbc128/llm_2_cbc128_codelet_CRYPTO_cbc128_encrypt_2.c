#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *in;
extern unsigned char *out;
extern size_t len;
extern size_t n;
extern  unsigned char *iv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size 2, unrolling to process two elements per iteration
    size_t i;
    for (i = 0; i < 16 && i < len; i += 2) {
        out[i] = in[i] ^ iv[i];
        if (i + 1 < 16 && i + 1 < len)
            out[i + 1] = in[i + 1] ^ iv[i + 1];
    }
}
