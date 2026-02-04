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
    for (j = 0; j < 1; ++j) {
        for (; i < len; ++i) {
            OPJ_INT32 y = c0[i];
            OPJ_INT32 u = c1[i];
            OPJ_INT32 v = c2[i];
            OPJ_INT32 g = y - ((u + v) >> 2);
            OPJ_INT32 r = v + g;
            OPJ_INT32 b = u + g;
            c0[i] = r;
            c1[i] = g;
            c2[i] = b;
        }
    }
}
