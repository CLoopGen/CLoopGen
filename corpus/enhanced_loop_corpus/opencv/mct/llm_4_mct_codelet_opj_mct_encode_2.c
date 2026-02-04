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
    for (; i < len; ++i) {
        OPJ_INT32 r = c0[i];
        OPJ_INT32 g = c1[i];
        OPJ_INT32 b = c2[i];
        OPJ_INT32 y = (r + (g * 2) + b) >> 2;
        OPJ_INT32 u = b - g;
        OPJ_INT32 v = r - g;
        if ((y & 0x80000000) == (u & 0x80000000)) {
            c0[i] = y;
            c1[i] = u;
            c2[i] = v;
        } else {
            c0[i] = 0;
            c1[i] = 0;
            c2[i] = 0;
        }
    }
}
