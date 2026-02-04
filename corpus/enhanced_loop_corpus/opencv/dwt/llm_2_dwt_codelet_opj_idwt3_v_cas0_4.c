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
    // Variant 1: Consecutive memory access by precomputing base pointer and using incremental addressing
    OPJ_INT32 *base = tiledp_col;
    OPJ_SIZE_T scaled_stride = stride * sizeof(OPJ_INT32);
    for (i = 0; i < len; ++i) {
        *base = tmp[i];
        base = (OPJ_INT32*)((char*)base + scaled_stride);
    }
}
