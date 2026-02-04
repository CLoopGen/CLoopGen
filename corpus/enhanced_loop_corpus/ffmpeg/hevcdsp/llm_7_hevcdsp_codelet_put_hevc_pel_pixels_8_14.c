#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int height;
extern int width;
extern int x;
extern int y;
extern uint8_t *src;
extern ptrdiff_t srcstride;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16_t *dst_local = dst;
    uint8_t *src_local = src;
    int offset = 0;
    for (y = 0; y < height; y++) {
        int limit = width;
        for (x = 0; x < limit; x++) {
            // Introduce artificial WAW and WAR dependencies by splitting computation
            int shifted_val = src_local[x] << (14 - 8);
            dst_local[x] = 0; // Write before actual use (WAW with next line)
            dst_local[x] = shifted_val;
        }
        offset += 64;
        src_local += srcstride;
        dst_local = dst + offset;
    }
}
