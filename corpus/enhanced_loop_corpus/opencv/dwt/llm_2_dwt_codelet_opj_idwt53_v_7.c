#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

extern OPJ_INT32 *tiledp_col;
extern OPJ_INT32 nb_cols;
extern OPJ_INT32 c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (c = 0; c < nb_cols; c++, tiledp_col++) {
        tiledp_col[0] /= 2;
    }
}
