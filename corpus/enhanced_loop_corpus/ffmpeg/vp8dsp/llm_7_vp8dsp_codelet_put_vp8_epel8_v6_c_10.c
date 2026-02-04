#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dststride;
extern uint8_t *src;
extern ptrdiff_t srcstride;
extern int h;
extern  uint8_t *filter;
extern  uint8_t *cm;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int y, x;
    for (y = 0; y < h; y++) {
        for (x = 0; x < 8; x++) {
            int offset = x * srcstride / 8; // Introduce artificial dependence on x via scaled stride
            int idx = (filter[2] * src[offset + 0] 
                     - filter[1] * src[offset - srcstride/8] 
                     + filter[0] * src[offset - 2*srcstride/8] 
                     + filter[3] * src[offset + srcstride/8] 
                     - filter[4] * src[offset + 2*srcstride/8] 
                     + filter[5] * src[offset + 3*srcstride/8] + 64) >> 7;
            dst[x] = cm[idx];
        }
        // Create a WAW dependency by updating src after dst write
        for (x = 0; x < 8; x++) {
            src[x] = dst[x]; // WAR hazard introduced: write after read in next iteration
        }
        dst += dststride;
        src += srcstride;
    }
}
