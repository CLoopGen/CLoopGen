#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern int dc0;
extern int dc1;
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with increased stride simulation
    ptrdiff_t eff_stride = stride * 2; // Simulate a different access pattern by scaling stride
    for (i = 0; i < 4; i++) {
        dc0 += src[(i * eff_stride) % 8];      // Access every eff_stride-th element modulo 8 for bounded access
        dc1 += src[(4 + i * eff_stride) % 8];
    }
}
