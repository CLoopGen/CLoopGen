#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *msrc;
extern  uint8_t *asrc;
extern uint8_t *dst;
extern ptrdiff_t mlinesize;
extern ptrdiff_t alinesize;
extern ptrdiff_t dlinesize;
extern int w;
extern int h;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *dst_cached = dst;
    uint8_t *msrc_cached = msrc;
    uint8_t *asrc_cached = asrc;
    for (y = 0; y < h; y++) {
        for (x = 0; x < w; x++) {
            int mval = msrc_cached[x] - 128;
            int aval = ((asrc_cached[x] >> 1) & 1) + asrc_cached[x];
            dst_cached[x] = ((mval * aval) >> 8) + 128;
        }
        dst_cached += dlinesize;
        msrc_cached += mlinesize;
        asrc_cached += alinesize;
    }
}
