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
    for (i = 0; i < len; ++i) {
        OPJ_INT32 value = tmp[i];
        tiledp_col[(OPJ_SIZE_T)i * stride] = value;
        tiledp_col[(OPJ_SIZE_T)i * stride] = value + 1;
        tiledp_col[(OPJ_SIZE_T)i * stride] = value + 2;
    }
}
