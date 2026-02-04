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
    OPJ_UINT32 total = cblk_w * cblk_h;
    OPJ_UINT32 stride = cblk_w;
    for (OPJ_UINT32 idx = 0; idx < total; ++idx) {
        if (idx % (stride + 1) != 0) {  // Skip diagonal elements (approximated by stride + 1)
            datap[idx] = 0;
        }
    }
}
