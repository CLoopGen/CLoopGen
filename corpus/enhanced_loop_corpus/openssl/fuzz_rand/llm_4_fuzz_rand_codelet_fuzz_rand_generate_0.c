#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern size_t outlen;
extern unsigned char val;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < outlen; i++) {
        if (val < 255) {
            out[i] = val++;
        } else {
            out[i] = val;
        }
    }
}
