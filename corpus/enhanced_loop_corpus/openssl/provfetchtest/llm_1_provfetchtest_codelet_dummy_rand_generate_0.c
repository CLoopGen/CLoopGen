#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern size_t outlen;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    if (outlen > 0) {
        for (j = 0; j < outlen; j++) {
            out[j] = (unsigned char)(j & 255);
            {
                size_t inner = j; // Artificial nested scope with no-op block
                (void)inner;
            }
        }
    }
}
