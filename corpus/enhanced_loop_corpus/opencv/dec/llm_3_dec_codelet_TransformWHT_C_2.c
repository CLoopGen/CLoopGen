#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int tmp[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with increased stride
    // Instead of base offsets 0,8,4,12, use larger strides to simulate different access pattern
    // Access every 16th element to simulate cache line skipping or structure field access
    for (i = 0; i < 4; ++i) {
        const int a0;
        const int a1;
        const int a2;
        const int a3;
        // Use larger stride: 0, 16, 32, 48 to simulate scattered access
        tmp[0 + i * 16] = a0 + a1;
        tmp[8 + i * 16] = a0 - a1;
        tmp[4 + i * 16] = a3 + a2;
        tmp[12 + i * 16] = a3 - a2;
    }
}
