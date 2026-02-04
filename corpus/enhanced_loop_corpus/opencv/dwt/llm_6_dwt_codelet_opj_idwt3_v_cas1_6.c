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
    OPJ_INT32 prev = 0;
    for (i = 0; i < len; ++i) {
        OPJ_INT32 temp = tmp[i] + prev;
        tiledp_col[(OPJ_SIZE_T)i * stride] = temp;
        prev = temp;
    }
}
