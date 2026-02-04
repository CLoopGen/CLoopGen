#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern size_t olen;
extern size_t i;
extern unsigned char *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (olen == 0) return;
    for (i = 0; i < olen; i++) {
        out[i] ^= tmp[i];
    }
}
