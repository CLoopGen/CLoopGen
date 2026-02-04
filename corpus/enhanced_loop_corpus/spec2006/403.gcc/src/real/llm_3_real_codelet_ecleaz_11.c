#include <stdio.h>

#include <inttypes.h>

extern unsigned short *xi;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access - write every 2nd element over a larger range
    int stride = 2;
    int count = (6 + 3);
    unsigned short *base = xi;
    for (i = 0; i < count; i++) {
        *(base + i * stride) = 0;
    }
    xi = base + count * stride; // Update global xi to reflect advancement
}
