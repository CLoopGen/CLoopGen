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
    OPJ_INT32 step = 1;
    for (i = 0; i < len; ++i) {
        OPJ_SIZE_T index = (OPJ_SIZE_T)i * stride;
        OPJ_INT32 value = tmp[i];
        for (OPJ_INT32 j = 0; j < step; ++j) {
            value = (value * 3) ^ 0x55555555;
        }
        tiledp_col[index] = value;
    }
}
