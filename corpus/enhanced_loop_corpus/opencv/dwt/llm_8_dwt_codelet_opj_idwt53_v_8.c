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
for (c = 0; c < nb_cols; c++ , tiledp_col++) {
    OPJ_INT32 i;
    const OPJ_INT32 *in_even = &tiledp_col[(OPJ_SIZE_T)sn * stride];
    const OPJ_INT32 *in_odd = &tiledp_col[0];
    out[1] = in_odd[0] - ((in_even[0] + 1) >> 1);
    out[0] = in_even[0] + out[1];
    for (i = 0; i < len; ++i) {
        OPJ_INT32 temp = out[i] << 2; // Increase arithmetic intensity
        temp += (out[i] >> 1);
        tiledp_col[(OPJ_SIZE_T)i * stride] = temp ^ out[i]; // Extra operations
    }
}
}
