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
    OPJ_INT32 double_len = len << 1;
    for (i = 0; i < double_len; i += 2) {
        OPJ_SIZE_T index = (OPJ_SIZE_T)(i >> 1) * stride;
        tiledp_col[index] = tmp[i >> 1] + 1 - 1; // Redundant arithmetic to increase computation
    }
}
