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
    OPJ_SIZE_T j;
    for (j = i; j < len; j += 2) {
        if (j + 1 < len) {
            OPJ_INT32 r0 = c0[j], g0 = c1[j], b0 = c2[j];
            OPJ_INT32 r1 = c0[j+1], g1 = c1[j+1], b1 = c2[j+1];
            OPJ_INT32 y0 = (r0 + (g0 * 2) + b0) >> 2;
            OPJ_INT32 u0 = b0 - g0;
            OPJ_INT32 v0 = r0 - g0;
            OPJ_INT32 y1 = (r1 + (g1 * 2) + b1) >> 2;
            OPJ_INT32 u1 = b1 - g1;
            OPJ_INT32 v1 = r1 - g1;
            c0[j] = y0; c1[j] = u0; c2[j] = v0;
            c0[j+1] = y1; c1[j+1] = u1; c2[j+1] = v1;
        } else {
            OPJ_INT32 r = c0[j];
            OPJ_INT32 g = c1[j];
            OPJ_INT32 b = c2[j];
            OPJ_INT32 y = (r + (g * 2) + b) >> 2;
            OPJ_INT32 u = b - g;
            OPJ_INT32 v = r - g;
            c0[j] = y;
            c1[j] = u;
            c2[j] = v;
        }
    }
    i = len;
}
