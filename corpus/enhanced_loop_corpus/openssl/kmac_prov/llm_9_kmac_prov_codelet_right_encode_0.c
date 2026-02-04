#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern size_t bits;
extern unsigned int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int shift = 0;
    for (i = 0; i < len; ++i) {
        out[i] = (unsigned char)((bits >> shift) & 255);
        shift += 8;
    }
}
