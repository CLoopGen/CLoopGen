#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dststride;
extern int h;
extern  uint8_t *filter;
extern  uint8_t *cm;
extern int x;
extern int y;
extern uint8_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access via Index Array
    // Use an index array to simulate non-unit strided access in a more data-abstracted way.
    const int offsets[] = { -32, -16, 0, 16, 32, 48 }; // Corresponds to: x-2*16, x-1*16, x+0*16, x+1*16, x+2*16, x+3*16
    int indices[6];
    for (y = 0; y < h; y++) {
        for (x = 0; x < 16; x++) {
            // Precompute indirect indices relative to current tmp base and x offset
            for (int i = 0; i < 6; i++) {
                indices[i] = (tmp - offsets[2] + x + offsets[i]) - tmp; // Normalize base to current x
            }
            int sum = filter[2] * tmp[indices[2]]
                    - filter[1] * tmp[indices[1]]
                    + filter[0] * tmp[indices[0]]
                    + filter[3] * tmp[indices[3]]
                    - filter[4] * tmp[indices[4]]
                    + filter[5] * tmp[indices[5]];
            dst[x] = cm[(sum + 64) >> 7];
        }
        dst += dststride;
        tmp += 16;
    }
}
