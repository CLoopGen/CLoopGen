#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern size_t outlen;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    unsigned char temp = 0;
    for (i = 0; i < outlen; i++) {
        temp = (unsigned char)((i + temp) & 255);
        out[i] = temp;
    }
}
