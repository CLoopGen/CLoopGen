#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern size_t i;
extern size_t bits;
extern size_t len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = len; i > 0; --i) {
        out[i] = (bits & 255);
        bits >>= 8;
        if ((bits & 255) == 0 && i > 1) {
            out[i - 1] = 0;
            --i;
        }
    }
}
