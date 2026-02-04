#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef uint32_t OPJ_UINT32;

extern  OPJ_UINT32 tile_w;
extern OPJ_UINT32 cblk_w;
extern OPJ_UINT32 cblk_h;
extern OPJ_UINT32 i;
extern OPJ_UINT32 j;
extern OPJ_UINT32 *restrict tiledp_u;
extern OPJ_UINT32 *restrict t1data;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < cblk_w * cblk_h; ++i) {  // Flatten nested loops and increase trip count
        OPJ_UINT32 row = i / cblk_w;
        OPJ_UINT32 col = i % cblk_w;
        if (row >= j && row < cblk_h) {
            t1data[0] = (tiledp_u[row * tile_w + col] << (7 - 1)) ^ 0x80;  // Add XOR to increase arithmetic operations
            t1data++;
        }
    }
}
