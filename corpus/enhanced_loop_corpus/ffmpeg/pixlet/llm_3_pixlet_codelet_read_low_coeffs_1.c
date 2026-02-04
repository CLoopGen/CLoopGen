#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int width;
extern ptrdiff_t stride;
extern unsigned int k;
extern unsigned int j;
extern int rlen;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with indirect indexing using a lookup pattern
    int16_t *base = dst;
    for (k = 0; k < rlen; k++) {
        int index = (j + k) % width;
        int row_offset = (j + k) / width;
        base[index + row_offset * (stride / sizeof(int16_t))] = 0;
    }
    // Update j and dst to reflect final position after rlen steps
    j = (j + rlen) % width;
    dst += (rlen / width) * stride;
}
