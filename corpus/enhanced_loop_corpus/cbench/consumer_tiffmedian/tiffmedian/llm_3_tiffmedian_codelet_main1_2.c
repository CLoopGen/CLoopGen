#include <stdio.h>

#include <inttypes.h>

typedef unsigned short uint16;

extern uint16 rm[256];
extern uint16 gm[256];
extern uint16 bm[256];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with stride of 8
    // This variant changes access pattern to strided to simulate non-contiguous data access, useful in scenarios like image channel processing
    int stride = 8;
    for (i = 0; i < 256; ++i) {
        int j = (i * stride) % 256;  // Ensure index remains within bounds using modulo
        rm[j] = ((rm[j] * ((1UL << 16) - 1)) / 255);
        gm[j] = ((gm[j] * ((1UL << 16) - 1)) / 255);
        bm[j] = ((bm[j] * ((1UL << 16) - 1)) / 255);
    }
}
