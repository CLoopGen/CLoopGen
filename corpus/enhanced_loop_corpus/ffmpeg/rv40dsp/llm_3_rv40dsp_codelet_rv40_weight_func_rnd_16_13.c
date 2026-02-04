#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src1;
extern uint8_t *src2;
extern int w1;
extern int w2;
extern ptrdiff_t stride;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with transposed iteration order (interleaved vertical access)
    for (i = 0; i < 16; i++) {
        for (j = 0; j < 16; j++) {
            // Access data with fixed column index 'i', stepping through rows via stride
            ptrdiff_t idx = j * stride;
            dst[idx + i] = ((((unsigned int)w2 * src1[idx + i]) >> 9) + 
                            (((unsigned int)w1 * src2[idx + i]) >> 9) + 16) >> 5;
        }
    }
    // Note: Final pointer adjustment not needed since original pointers are extern and not used post-loop
}
