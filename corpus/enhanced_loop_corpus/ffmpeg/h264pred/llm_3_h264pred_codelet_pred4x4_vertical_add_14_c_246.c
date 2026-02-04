#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern uint16_t *pix;
extern  int32_t *block;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with reversed block indexing and fixed pixel base
    // Memory access pattern now uses a fixed pixel base with increasing strided writes
    uint16_t *pix_base = pix;
    for (i = 0; i < 4; i++) {
        uint16_t v = pix_base[i];
        v += block[0]; pix_base[(i + 1) * stride] = v;
        v += block[1]; pix_base[(i + 2) * stride] = v;
        v += block[2]; pix_base[(i + 3) * stride] = v;
        v += block[3]; pix_base[(i + 4) * stride] = v;
        block += 4; // Advance block in chunks of 4 instead of 1
    }
}
