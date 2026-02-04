#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

typedef int32_t OPJ_INT32;
typedef uint32_t OPJ_UINT32;
typedef size_t OPJ_SIZE_T;

OPJ_INT32 *restrict datap;
OPJ_UINT32 cblk_w;
OPJ_UINT32 cblk_h;
OPJ_UINT32 i;
OPJ_UINT32 j;
OPJ_UINT32 tile_w;
OPJ_INT32 *restrict tiledp;

void init_vars() {
    cblk_w = 1024;
    cblk_h = 512;
    tile_w = 2048;

    OPJ_SIZE_T data_size = (OPJ_SIZE_T)cblk_h * cblk_w;
    OPJ_SIZE_T tile_size = (OPJ_SIZE_T)cblk_h * tile_w;

    datap = (OPJ_INT32*)aligned_alloc(64, data_size * sizeof(OPJ_INT32));
    tiledp = (OPJ_INT32*)aligned_alloc(64, tile_size * sizeof(OPJ_INT32));

    for (OPJ_SIZE_T idx = 0; idx < data_size; ++idx) {
        datap[idx] = (OPJ_INT32)(idx % 1000);
    }

    memset(tiledp, 0, tile_size * sizeof(OPJ_INT32));
}