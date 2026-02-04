#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern size_t olen;
extern size_t i;
extern unsigned char *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t step = 2;
    for (i = 0; i < olen; i += step) {
        if (i + 1 < olen) {
            out[i] ^= tmp[i];
            out[i + 1] ^= tmp[i + 1];
        } else {
            out[i] ^= tmp[i];
        }
    }
}
