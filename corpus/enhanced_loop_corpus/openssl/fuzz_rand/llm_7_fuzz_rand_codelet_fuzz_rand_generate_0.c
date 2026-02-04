#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern size_t outlen;
extern unsigned char val;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < outlen; i += 2) {
        if (i + 1 < outlen) {
            out[i]     = val++;
            out[i + 1] = val++;
        } else {
            out[i] = val++;
        }
    }
}
