#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern size_t outlen;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j, k;
    for (j = 0; j < outlen; j += 16) {
        for (k = j; k < outlen && k < j + 16; k++) {
            out[k] = (unsigned char)(k & 255);
        }
    }
}
