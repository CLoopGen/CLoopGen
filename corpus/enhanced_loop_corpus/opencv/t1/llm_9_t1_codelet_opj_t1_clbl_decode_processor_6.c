#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

typedef uint32_t OPJ_UINT32;

extern OPJ_INT32 *restrict datap;
extern OPJ_UINT32 i;
extern OPJ_UINT32 cblk_size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    OPJ_UINT32 limit = cblk_size * 3;
    for (i = 0; i < limit; ++i) {
        OPJ_UINT32 idx = i % cblk_size;
        datap[idx] = (datap[idx] + datap[idx] / 2) / 2; // More complex arithmetic: equivalent to scaling down by ~0.75 then by 0.5
    }
}
