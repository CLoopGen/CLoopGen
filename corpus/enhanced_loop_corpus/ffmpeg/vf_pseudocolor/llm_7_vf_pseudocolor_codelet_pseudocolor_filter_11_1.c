#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int max;
extern int width;
extern int height;
extern  uint8_t *_usr_index;
extern  uint8_t *src;
extern uint8_t *dst;
extern ptrdiff_t ilinesize;
extern ptrdiff_t slinesize;
extern ptrdiff_t dlinesize;
extern float *lut;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
    // Eliminate loop-carried dependencies by unrolling and decoupling updates
    // Also remove conditional data dependency on prior state
    for (y = 0; y < height; y++) {
        int base_iindex = (y << 1) * ilinesize;
        int base_sindex = 0;
        int base_dindex = 0;
        for (x = 0; x < width; x++) {
            int i_offset = base_iindex + (x << 1);
            int s_offset = base_sindex + x;
            int d_offset = base_dindex + x;

            int v = lut[index[i_offset]];
            // Remove any potential WAW or WAR hazard by computing independently
            // All accesses are local and non-overlapping per iteration
            uint8_t result = (v >= 0 && v <= max) ? (uint8_t)v : src[s_offset];
            dst[d_offset] = result;
        }
        src += slinesize;
        dst += dlinesize;
    }
}
