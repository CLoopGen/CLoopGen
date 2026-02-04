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
    for (i = 0; i < cblk_w; ++i) {
        OPJ_UINT32 k;
        OPJ_UINT32 base_offset = i;
        for (k = j; k < cblk_h; k++) {
            OPJ_UINT32 read_val = tiledp_u[k * tile_w + base_offset];
            t1data[(k - j) * cblk_w] = read_val << (7 - 1); 
        }
    }
    t1data += (cblk_h - j) * cblk_w; 
}
