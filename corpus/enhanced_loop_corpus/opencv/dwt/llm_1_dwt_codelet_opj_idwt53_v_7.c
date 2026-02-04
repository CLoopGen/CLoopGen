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
    OPJ_INT32 outer_c;
    for (outer_c = 0; outer_c < nb_cols; outer_c++) {
        c = outer_c;
        {
            tiledp_col[0] /= 2;
            tiledp_col++;
        }
    }
}
