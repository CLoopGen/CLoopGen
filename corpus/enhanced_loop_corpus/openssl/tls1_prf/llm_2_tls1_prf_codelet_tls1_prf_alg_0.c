#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern size_t olen;
extern size_t i;
extern unsigned char *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    size_t stride = 2;
    for (i = 0; i < olen; i += stride) {
        if (i + 0 < olen) out[i + 0] ^= tmp[i + 0];
        if (i + 1 < olen) out[i + 1] ^= tmp[i + 1];
    }
}
