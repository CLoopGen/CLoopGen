#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef uint32_t OPJ_UINT32;

OPJ_UINT32 tile_w = 64;
OPJ_UINT32 cblk_w = 32;
OPJ_UINT32 cblk_h = 32;
OPJ_UINT32 i;
OPJ_UINT32 j = 0;
OPJ_UINT32 *restrict tiledp_u;
OPJ_UINT32 *restrict t1data;

static OPJ_UINT32 tiledp_u_data[2097152]; // ~8MB to ensure sufficient data
static OPJ_UINT32 t1data_buffer[1048576]; // ~4MB working space

void init_vars() {
    // Ensure cblk_w and cblk_h are within safe bounds
    tile_w = 2048;
    cblk_w = 128;
    cblk_h = 128;
    j = 0;

    // Allocate and initialize tiledp_u to point into pre-allocated array
    // Make sure we have enough data: k * tile_w + i < size
    for (size_t idx = 0; idx < 2097152; ++idx) {
        tiledp_u_data[idx] = (OPJ_UINT32)(idx % 256);
    }
    tiledp_u = tiledp_u_data;

    // Initialize t1data buffer
    for (size_t idx = 0; idx < 1048576; ++idx) {
        t1data_buffer[idx] = 0;
    }
    t1data = t1data_buffer;
}