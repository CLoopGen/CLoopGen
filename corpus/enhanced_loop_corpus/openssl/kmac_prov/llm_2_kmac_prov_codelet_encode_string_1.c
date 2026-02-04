#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern size_t i;
extern size_t bits;
extern size_t len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive forward memory access with index remapping
    size_t idx = 1;
    for (i = 0; i < len; ++i) {
        out[idx] = (bits >> (i * 8)) & 255;
        idx += 1;
    }
}
