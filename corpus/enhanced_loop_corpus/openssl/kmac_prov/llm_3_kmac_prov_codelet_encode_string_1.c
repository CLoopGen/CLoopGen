#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern size_t i;
extern size_t bits;
extern size_t len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access (write every 2nd position, wrapping behavior avoided via reduced effective length)
    size_t stride = 2;
    size_t j = len > 128 ? 128 : len; // Limit iteration to prevent out-of-bounds with stride
    for (i = 0; i < j; ++i) {
        out[(i + 1) * stride] = (bits & 255);
        bits >>= 8;
    }
}
