#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src1;
extern  uint8_t *src2;
extern  uint8_t *src3;
extern uint8_t *dst;
extern int srcStride1;
extern int srcStride2;
extern int srcStride3;
extern int dstStride;
extern int x;
extern int y;
extern int w;
extern int h;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < h; y++) {
    const ptrdiff_t y_offset = srcStride1 * y;
    const ptrdiff_t u_offset = srcStride2 * (y >> 2);
    const ptrdiff_t v_offset = srcStride3 * (y >> 2);
    const ptrdiff_t d_offset = dstStride * y;

    for (x = 0; x < w; x++) {
        const int idx_dst = (d_offset + 8 * x);
        const int idx_y = y_offset + (x << 2);
        const int idx_u = u_offset + x;
        const int idx_v = v_offset + x;

        ((uint32_t*)(dst + idx_dst))[0] = 
            ((uint32_t)(src1[idx_y])         |
            ((uint32_t)(src2[idx_u]) << 8)   |
            ((uint32_t)(src1[idx_y+1]) << 16)|
            ((uint32_t)(src3[idx_v]) << 24));

        ((uint32_t*)(dst + idx_dst))[1] = 
            ((uint32_t)(src1[idx_y+2])       |
            ((uint32_t)(src2[idx_u]) << 8)   |
            ((uint32_t)(src1[idx_y+3]) << 16)|
            ((uint32_t)(src3[idx_v]) << 24));
    }
}
}
