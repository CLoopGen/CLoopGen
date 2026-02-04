#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int n;
extern int sixel_palet[1024];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access (write every 4th element)
    int stride = 4;
    for (i = 0; i < 24; i++) {
        int val = (i * 11) & 255;
        int rgb = (val << 16) + (val << 8) + val;
        sixel_palet[n * stride + i] = rgb;
    }
    n += 24;  // Update n to reflect logical advancement
}
