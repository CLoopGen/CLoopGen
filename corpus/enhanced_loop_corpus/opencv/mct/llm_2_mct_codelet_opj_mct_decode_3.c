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
    OPJ_SIZE_T stride = 2;
    for (; i < len; i += stride) {
        if (i + stride - 1 >= len) break;
        OPJ_INT32 y0 = c0[i];
        OPJ_INT32 u0 = c1[i];
        OPJ_INT32 v0 = c2[i];
        OPJ_INT32 g0 = y0 - ((u0 + v0) >> 2);
        OPJ_INT32 r0 = v0 + g0;
        OPJ_INT32 b0 = u0 + g0;
        c0[i] = r0;
        c1[i] = g0;
        c2[i] = b0;

        OPJ_INT32 y1 = c0[i+1];
        OPJ_INT32 u1 = c1[i+1];
        OPJ_INT32 v1 = c2[i+1];
        OPJ_INT32 g1 = y1 - ((u1 + v1) >> 2);
        OPJ_INT32 r1 = v1 + g1;
        OPJ_INT32 b1 = u1 + g1;
        c0[i+1] = r1;
        c1[i+1] = g1;
        c2[i+1] = b1;
    }
}
