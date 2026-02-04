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
    OPJ_INT32 step = 2;
    for (i = 0; i < len; i += step) {
        if (i + 1 < len) {
            tiledp_col[(OPJ_SIZE_T)i * stride] = tmp[i];
            tiledp_col[(OPJ_SIZE_T)(i + 1) * stride] = tmp[i + 1];
        } else {
            tiledp_col[(OPJ_SIZE_T)i * stride] = tmp[i];
        }
    }
}
