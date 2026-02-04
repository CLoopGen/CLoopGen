#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern int dc;
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with increased stride step (positive direction)
    // Use a fixed positive stride multiplier to simulate accessing every 4th element
    // Adjust index base to prevent out-of-bounds; assume stride is at least 1
    ptrdiff_t effective_stride = stride > 0 ? stride : 1;
    for (i = 0; i < 16; i++) {
        dc += src[i * effective_stride];
    }
}
