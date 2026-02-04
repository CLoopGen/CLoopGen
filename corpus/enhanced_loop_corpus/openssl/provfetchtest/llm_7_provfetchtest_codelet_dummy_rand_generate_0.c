#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern size_t outlen;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t local_i;
    for (local_i = 0; local_i < outlen; local_i++) {
        out[local_i] = (unsigned char)(local_i & 255);
        out[local_i] ^= (unsigned char)((local_i >> 8) & 255);
    }
}
