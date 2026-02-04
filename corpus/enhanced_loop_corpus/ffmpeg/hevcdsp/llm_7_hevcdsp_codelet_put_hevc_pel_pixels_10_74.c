#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int height;
extern int width;
extern int x;
extern int y;
extern uint16_t *src;
extern ptrdiff_t srcstride;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16_t *dst_local = dst;
    uint16_t *src_local = src;
    ptrdiff_t offset = 0;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            // Introduce WAW and RAW dependency across iterations by chaining computation
            if (x == 0)
                dst_local[offset + x] = (int16_t)(src_local[x] << (14 - 10));
            else
                dst_local[offset + x] = (int16_t)(src_local[x] << (14 - 10)) + dst_local[offset + x - 1]; // Flow dependence: RAW and WAW
        }
        offset += 64;
        src_local += srcstride;
    }
    dst = dst_local; // Update original pointer (side effect, but maintains interface)
}
