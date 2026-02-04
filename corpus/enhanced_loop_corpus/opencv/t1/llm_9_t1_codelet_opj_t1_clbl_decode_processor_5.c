#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

typedef uint32_t OPJ_UINT32;

extern OPJ_INT32 *restrict datap;
extern OPJ_UINT32 cblk_w;
extern OPJ_UINT32 cblk_h;
extern OPJ_UINT32 i;
extern OPJ_UINT32 j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    OPJ_UINT32 factor = (cblk_w > cblk_h) ? cblk_w : cblk_h;
    OPJ_UINT32 stride = (factor + 3) & ~3; // Align to multiple of 4 for padding
    for (OPJ_UINT32 j = 0; j < cblk_h; ++j) {
        for (OPJ_UINT32 i = 0; i < cblk_w; ++i) {
            OPJ_UINT32 offset = (j * stride) + i;
            datap[offset] = (j % 2 == 0) ? (i % 2 == 0 ? 0 : -1) : (i % 2 == 0 ? -1 : 0);
        }
    }
}
