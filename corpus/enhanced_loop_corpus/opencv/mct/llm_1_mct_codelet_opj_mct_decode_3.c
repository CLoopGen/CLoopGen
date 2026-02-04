#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

typedef size_t OPJ_SIZE_T;

extern OPJ_INT32 *restrict c0;
extern OPJ_INT32 *restrict c1;
extern OPJ_INT32 *restrict c2;
extern OPJ_SIZE_T i;
extern  OPJ_SIZE_T len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    OPJ_SIZE_T outer_start = i;
    OPJ_SIZE_T outer_end = len;
    OPJ_SIZE_T block_size = 16;
    for (OPJ_SIZE_T ii = 0; ii * block_size < (outer_end - outer_start); ++ii) {
        OPJ_SIZE_T start = outer_start + ii * block_size;
        OPJ_SIZE_T end = start + block_size;
        if (end > outer_end) end = outer_end;
        for (OPJ_SIZE_T local_i = start; local_i < end; ++local_i) {
            OPJ_INT32 y = c0[local_i];
            OPJ_INT32 u = c1[local_i];
            OPJ_INT32 v = c2[local_i];
            OPJ_INT32 g = y - ((u + v) >> 2);
            OPJ_INT32 r = v + g;
            OPJ_INT32 b = u + g;
            c0[local_i] = r;
            c1[local_i] = g;
            c2[local_i] = b;
        }
    }
    i = outer_end;
}
