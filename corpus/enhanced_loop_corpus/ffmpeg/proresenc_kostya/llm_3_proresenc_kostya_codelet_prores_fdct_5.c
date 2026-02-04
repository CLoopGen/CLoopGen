#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t linesize;
extern int16_t *block;
extern int x;
extern int y;
extern  uint16_t *tsrc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with reversed traversal and stride emulation
    ptrdiff_t stride_in_elements = linesize >> 1;
    for (x = 0; x < 8; x++) {
        for (y = 0; y < 8; y++) {
            block[y * 8 + (7 - x)] = tsrc[y * stride_in_elements + x];
        }
    }
}
