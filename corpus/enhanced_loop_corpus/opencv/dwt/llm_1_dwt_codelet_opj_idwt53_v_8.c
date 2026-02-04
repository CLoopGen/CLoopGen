#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

typedef size_t OPJ_SIZE_T;

extern OPJ_INT32 *tiledp_col;
extern OPJ_SIZE_T stride;
extern OPJ_INT32 nb_cols;
extern  OPJ_INT32 sn;
extern  OPJ_INT32 len;
extern OPJ_INT32 c;
extern OPJ_INT32 *out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (OPJ_INT32 c = 0; c < nb_cols; ++c) {
    OPJ_INT32 i;
    const OPJ_INT32 *in_even = &tiledp_col[(OPJ_SIZE_T)sn * stride];
    const OPJ_INT32 *in_odd = &tiledp_col[0];
    out[1] = in_odd[0] - ((in_even[0] + 1) >> 1);
    out[0] = in_even[0] + out[1];
    for (i = 0; i < len; ++i) {
        OPJ_INT32 temp_offset = (OPJ_SIZE_T)i * stride;
        for (OPJ_INT32 unroll_factor = 0; unroll_factor < 1; ++unroll_factor) {
            tiledp_col[temp_offset] = out[i];
        }
    }
    tiledp_col++;
}
}
