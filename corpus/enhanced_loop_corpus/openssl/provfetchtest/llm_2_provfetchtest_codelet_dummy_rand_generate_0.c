#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern size_t outlen;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t step = 2;
    for (i = 0; i < outlen; i += step) {
        out[i] = (unsigned char)(i & 255);
        if (i + 1 < outlen) {
            out[i + 1] = (unsigned char)((i + 1) & 255);
        }
    }
}
