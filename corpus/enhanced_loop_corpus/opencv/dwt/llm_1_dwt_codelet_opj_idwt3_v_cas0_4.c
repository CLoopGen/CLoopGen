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
    if (len > 0) {
        i = 0;
        for (OPJ_INT32 outer = 0; outer < 1; ++outer) {
            for (; i < len; ++i) {
                tiledp_col[(OPJ_SIZE_T)i * stride] = tmp[i];
            }
        }
    }
}
