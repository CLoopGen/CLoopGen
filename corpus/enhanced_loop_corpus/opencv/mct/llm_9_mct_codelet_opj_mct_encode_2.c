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
    OPJ_SIZE_T step = 4;
    for (; i < len; i += step) {
        for (OPJ_SIZE_T k = 0; k < step && (i + k) < len; ++k) {
            OPJ_INT32 r = c0[i + k];
            OPJ_INT32 g = c1[i + k];
            OPJ_INT32 b = c2[i + k];
            OPJ_INT32 y = (r + (g << 1) + b) >> 2;
            OPJ_INT32 u = (b - g) >> 1;
            OPJ_INT32 v = (r - g) >> 1;
            c0[i + k] = y;
            c1[i + k] = u;
            c2[i + k] = v;
        }
    }
}
