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
    OPJ_UINT32 total_elements = cblk_h * tile_w;
    OPJ_UINT32 linear_idx = 0;
    OPJ_INT32 *data_ptr = datap;
    OPJ_FLOAT32 *tile_ptr = tiledp;

    for (linear_idx = 0; linear_idx < total_elements; ++linear_idx) {
        OPJ_UINT32 within_row = linear_idx % tile_w;
        if (within_row < cblk_w) {
            OPJ_FLOAT32 tmp = (OPJ_FLOAT32)data_ptr[within_row] * stepsize;
            tile_ptr[linear_idx] = tmp;
        } else {
            tile_ptr[linear_idx] = 0.0f; // Padding outside cblk_w remains zero or unused
        }
        if (within_row == tile_w - 1) {
            data_ptr += cblk_w; // Move data pointer by actual block width after each row
        }
    }
    datap = data_ptr; // Update global datap if needed (though not strictly necessary for read-only)
}
