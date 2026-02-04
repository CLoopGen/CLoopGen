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
    // Variant 2: Reduced computational intensity with conditional skipping and reduced effective trip count
    // Every other iteration is skipped, reducing total operations while keeping loop structure
    int y;
    for (y = 0; y < b_h; y += 2) {  // Increase step size to reduce trip count by half
        ptrdiff_t offset = y * stride;
        // Maintain original store pattern but applied less frequently
        *(uint32_t *)&dst[0 + offset] = color4;
        *(uint32_t *)&dst[4 + offset] = color4;
        *(uint32_t *)&dst[8 + offset] = color4;
        *(uint32_t *)&dst[12 + offset] = color4;
    }
}
