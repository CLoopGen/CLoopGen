#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int32_t OPJ_INT32;
typedef uint32_t OPJ_UINT32;
typedef float OPJ_FLOAT32;

OPJ_INT32 *restrict datap;
OPJ_UINT32 cblk_w = 512;
OPJ_UINT32 cblk_h = 512;
OPJ_UINT32 i;
OPJ_UINT32 j;
OPJ_UINT32 tile_w = 1024;
float stepsize = 0.5f;
OPJ_FLOAT32 *restrict tiledp;

void init_vars() {
    size_t total_size = (size_t)tile_w * cblk_h;
    datap = (OPJ_INT32*)aligned_alloc(64, sizeof(OPJ_INT32) * cblk_w * cblk_h);
    tiledp = (OPJ_FLOAT32*)aligned_alloc(64, sizeof(OPJ_FLOAT32) * total_size);

    for (size_t idx = 0; idx < cblk_w * cblk_h; ++idx) {
        datap[idx] = (OPJ_INT32)(idx % 1000);
    }

    for (size_t idx = 0; idx < total_size; ++idx) {
        tiledp[idx] = 0.0f;
    }
}