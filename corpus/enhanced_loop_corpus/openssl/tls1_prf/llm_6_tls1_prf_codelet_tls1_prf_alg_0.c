#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern size_t olen;
extern size_t i;
extern unsigned char *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (j = 0; j < olen; j += 2) {
        if (j + 1 < olen) {
            out[j] ^= tmp[j];
            out[j + 1] ^= tmp[j + 1];
        } else {
            out[j] ^= tmp[j];
        }
    }
}
