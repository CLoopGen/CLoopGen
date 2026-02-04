#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern size_t i;
extern size_t bits;
extern size_t len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (i = len; i > 0; --i) {
        unsigned char byte = (unsigned char)(bits & 255);
        out[i] = byte;
        bits >>= 8;
        // Add extra arithmetic to increase computational intensity
        for (j = 0; j < 3; ++j) {
            byte ^= (byte << 1) ^ (0x55 >> j);
        }
    }
}
