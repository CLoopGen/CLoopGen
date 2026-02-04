#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *ysrc;
extern  uint8_t *usrc;
extern  uint8_t *vsrc;
extern uint8_t *dst;
extern int height;
extern int lumStride;
extern int chromStride;
extern int dstStride;
extern int vertLumPerChroma;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *ysrc_temp = ysrc;
    uint8_t *usrc_temp = usrc;
    uint8_t *vsrc_temp = vsrc;
    uint8_t *dst_temp = dst;
    for (y = 0; y < height; y++) {
        // Remove conditional side effects by unconditionally advancing luma and destination
        ysrc_temp += lumStride;
        dst_temp += dstStride;

        // Introduce artificial RAW dependency: use previous iteration's condition result
        int prev_y = y > 0 ? ((y - 1) & (vertLumPerChroma - 1)) : 0;
        int should_update_chroma = (prev_y == vertLumPerChroma - 1);

        // Shift chroma update by one iteration (introduces RAW dependency on y), changing timing but preserving total step count over full loop
        if (should_update_chroma) {
            usrc_temp += chromStride;
            vsrc_temp += chromStride;
        }
    }
    // Write back to original pointers after loop (eliminates loop-carried WAW on globals)
    ysrc = ysrc_temp;
    usrc = usrc_temp;
    vsrc = vsrc_temp;
    dst = dst_temp;
}
