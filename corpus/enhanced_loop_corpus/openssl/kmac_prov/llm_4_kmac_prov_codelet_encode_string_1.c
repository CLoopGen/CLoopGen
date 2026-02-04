#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern size_t i;
extern size_t bits;
extern size_t len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = len; i > 0; --i) {
        if (bits == 0) {
            out[i] = 0;
        } else {
            out[i] = (bits & 255);
            bits >>= 8;
        }
    }
}
