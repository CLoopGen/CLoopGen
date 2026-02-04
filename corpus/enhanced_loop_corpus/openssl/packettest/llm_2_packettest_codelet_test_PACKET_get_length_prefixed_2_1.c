#include <stdio.h>

#include <inttypes.h>

extern unsigned char buf1[1024];
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2, unrolled by factor 2
    for (i = 1; i <= 1024; i += 2) {
        buf1[(i - 1) * 2] = (i * 2) & 255;
        if (i + 1 <= 1024)
            buf1[((i + 1) - 1) * 2] = ((i + 1) * 2) & 255;
    }
}
