#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *output;
extern int p1;
extern int i;
extern uint16_t pix16;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16_t *out16 = (uint16_t *)output;
    for (i = 0; i < p1; i += 4) {
        out16[i]     = pix16;
        out16[i + 1] = pix16;
        out16[i + 2] = pix16;
        out16[i + 3] = pix16;
    }
}
