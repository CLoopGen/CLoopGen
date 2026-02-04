#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t stride;
extern int b_h;
extern int y;
extern  unsigned int color4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t temp_val = color4 ^ color4; // Introduce artificial dependency: temp_val = 0, breaks direct use of color4
    temp_val = color4; // WAW: Write-after-write on temp_val, removes direct memory-color4 coupling momentarily
    for (y = 0; y < b_h; y++) {
        uint8_t offset = 0;
        *(uint32_t *)&dst[offset + y * stride] = temp_val; offset += 4;
        *(uint32_t *)&dst[offset + y * stride] = temp_val; offset += 4;
        *(uint32_t *)&dst[offset + y * stride] = temp_val; offset += 4;
        *(uint32_t *)&dst[offset + y * stride] = temp_val; offset += 4;
        *(uint32_t *)&dst[offset + y * stride] = temp_val; offset += 4;
        *(uint32_t *)&dst[offset + y * stride] = temp_val; offset += 4;
        *(uint32_t *)&dst[offset + y * stride] = temp_val; offset += 4;
        *(uint32_t *)&dst[offset + y * stride] = temp_val;
        // Introduce loop-carried dependency via offset reuse (artificial RAW)
    }
}
