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
    OPJ_UINT32 *local_tiledp = tiledp_u;
    OPJ_UINT32 *local_t1data = t1data;
    OPJ_UINT32 total_elements = cblk_h - j;
    OPJ_UINT32 col, row;
    for (col = 0; col < cblk_w; ++col) {
        OPJ_UINT32 src_index = j * tile_w + col;
        for (row = 0; row < total_elements; row++) {
            local_t1data[row] = local_tiledp[src_index + row * tile_w] << 6;
        }
        local_t1data += total_elements;
    }
    t1data = local_t1data;
}
