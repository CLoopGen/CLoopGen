#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern size_t olen;
extern size_t i;
extern unsigned char *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned char prev = 0;
    for (i = 0; i < olen; i++) {
        unsigned char temp = out[i];
        out[i] ^= tmp[i] ^ prev;
        prev = temp;
    }
}
