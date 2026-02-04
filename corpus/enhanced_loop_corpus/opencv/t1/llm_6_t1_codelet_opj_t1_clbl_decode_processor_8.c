#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

typedef uint32_t OPJ_UINT32;

typedef float OPJ_FLOAT32;

extern OPJ_INT32 *restrict datap;
extern OPJ_UINT32 cblk_w;
extern OPJ_UINT32 cblk_h;
extern OPJ_UINT32 i;
extern OPJ_UINT32 j;
extern OPJ_UINT32 tile_w;
extern  float stepsize;
extern OPJ_FLOAT32 *restrict tiledp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < cblk_h; ++j) {
        OPJ_FLOAT32 *restrict tiledp2 = tiledp;
        OPJ_INT32 *restrict datap_local = datap;
        for (i = 0; i < cblk_w; ++i) {
            OPJ_FLOAT32 tmp = (OPJ_FLOAT32)datap_local[i] * stepsize;
            tiledp2[i] = tmp;
        }
        datap += cblk_w;
        tiledp += tile_w;
    }
}
