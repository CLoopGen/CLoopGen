#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern size_t olen;
extern size_t i;
extern unsigned char *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < olen * 2; i += 2) {
        size_t idx = i >> 1;
        if (idx < olen) {
            out[idx] ^= tmp[idx] ^ (unsigned char)(idx & 0xFF);
        }
    }
}
