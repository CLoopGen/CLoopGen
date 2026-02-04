#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int height;
extern int width;
extern int x;
extern int y;
extern uint8_t *src;
extern ptrdiff_t srcstride;
extern  int8_t *filter;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < height + 3; y++) {
        int16_t local_accum[64]; // Local accumulation to remove direct write to shared tmp early
        for (x = 0; x < width; x++) {
            // Break direct WAW and WAR dependencies on tmp by using local storage
            int32_t val = filter[0] * src[x - 1] 
                        + filter[1] * src[x] 
                        + filter[2] * src[x + 1] 
                        + filter[3] * src[x + 2];
            local_accum[x] = val >> 8;
        }
        // Now write back to tmp with offset, eliminating loop-carried dependency on tmp
        for (x = 0; x < width; x++) {
            tmp[x] = local_accum[x];
        }
        src += srcstride;
        tmp += 64;
    }
}
