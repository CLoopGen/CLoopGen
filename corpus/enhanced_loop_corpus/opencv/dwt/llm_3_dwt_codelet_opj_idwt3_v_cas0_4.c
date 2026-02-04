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
    // Variant 2: Strided access with reversed loop order and alternating pattern to increase stride diversity
    OPJ_SIZE_T idx;
    for (i = len - 1; i >= 0; --i) {
        idx = ((OPJ_SIZE_T)(len - 1 - i)) * stride;
        tiledp_col[idx] = tmp[i];
    }
}
