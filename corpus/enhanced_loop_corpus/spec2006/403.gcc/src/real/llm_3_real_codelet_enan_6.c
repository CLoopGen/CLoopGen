#include <stdio.h>

#include <inttypes.h>

extern unsigned short *x;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access — write every other element
    unsigned short *base = x;
    int stride = 2;
    int count = 6 - 2;
    for (i = 0; i < count; i++) {
        base[i * stride] = 0;  // Write with stride of 2
    }
    x = base + (count * stride);  // Update x to point past the last accessed element
}
