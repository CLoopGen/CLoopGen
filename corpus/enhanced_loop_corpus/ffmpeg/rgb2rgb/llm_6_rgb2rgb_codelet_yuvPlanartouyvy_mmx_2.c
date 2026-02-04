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
    int idx = 0;
    for (y = 0; y < height; y++) {
        int chroma_update = (y & (vertLumPerChroma - 1)) == (vertLumPerChroma - 1);
        // Introduce a temporary variable that creates a WAW dependency on 'idx', breaking direct update of pointers until end
        if (chroma_update) {
            idx += chromStride;
        }
        // Delay the actual pointer updates: now usrc/vsrc depend on final value of idx (loop-carried WAW introduced)
    }
    // Move pointer arithmetic outside loop to eliminate loop-carried RAW dependencies inside
    ysrc += lumStride * height;
    dst += dstStride * height;
    usrc += idx;
    vsrc += idx;
}
