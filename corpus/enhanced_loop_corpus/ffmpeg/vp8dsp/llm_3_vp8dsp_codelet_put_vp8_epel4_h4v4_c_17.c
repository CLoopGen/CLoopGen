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
    // Variant 2: Strided memory access transformed to indirect access via index array
    // Use a fixed offset table to simulate irregular but predictable access pattern
    const int offsets[4] = {0, -4, 4, 8}; // Corresponds to [x+0*4], [x-1*4], [x+1*4], [x+2*4] at base x=0
    uint8_t **ptrs = (uint8_t**)alloca(4 * sizeof(uint8_t*));
    
    for (y = 0; y < h; y++) {
        for (int x = 0; x < 4; x++) {
            ptrs[0] = &tmp[x + offsets[0]];
            ptrs[1] = &tmp[x + offsets[1]];
            ptrs[2] = &tmp[x + offsets[2]];
            ptrs[3] = &tmp[x + offsets[3]];

            dst[x] = cm[(filter[2] * (*ptrs[0]) - filter[1] * (*ptrs[1]) +
                         filter[3] * (*ptrs[2]) - filter[4] * (*ptrs[3]) + 64) >> 7];
        }
        dst += dststride;
        tmp += 4;
    }
}
