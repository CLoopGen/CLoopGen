#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern size_t outlen;
extern unsigned char val;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t step = 2;
    for (i = 0; i < outlen; i += step) {
        if (i + 0 < outlen) out[i + 0] = val++;
        if (i + 1 < outlen) out[i + 1] = val++;
    }
}
