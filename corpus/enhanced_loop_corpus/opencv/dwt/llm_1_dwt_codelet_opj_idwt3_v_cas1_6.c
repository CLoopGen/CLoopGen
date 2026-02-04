#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

typedef size_t OPJ_SIZE_T;

extern OPJ_INT32 *tmp;
extern  OPJ_INT32 len;
extern OPJ_INT32 *tiledp_col;
extern  OPJ_SIZE_T stride;
extern OPJ_INT32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    OPJ_INT32 outer_i;
    OPJ_INT32 inner_i;
    for (outer_i = 0; outer_i < len; ++outer_i) {
        inner_i = outer_i;
        tiledp_col[(OPJ_SIZE_T)inner_i * stride] = tmp[inner_i];
    }
}
