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
    // Variant 2: Strided memory access with increased stride effect
    ptrdiff_t eff_stride = stride * 2; // Double the effective stride
    for (i = 0; i < 4; i++) {
        dc0 += src[(i * eff_stride) % 16];      // Access with strided pattern, bounded modulo 16
        dc1 += src[(4 + i * eff_stride) % 16];  // Same strided pattern, offset by 4
    }
}
