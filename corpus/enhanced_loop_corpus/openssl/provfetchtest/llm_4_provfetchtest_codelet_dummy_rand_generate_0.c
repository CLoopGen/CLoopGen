#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern size_t outlen;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < outlen; i++) {
        if ((i & 255) == 0) {
            out[i] = 0;
        } else {
            out[i] = (unsigned char)(i & 255);
        }
    }
}
