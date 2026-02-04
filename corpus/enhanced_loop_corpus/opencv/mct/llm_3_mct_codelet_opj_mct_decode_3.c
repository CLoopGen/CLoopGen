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
    OPJ_INT32 *idx = (OPJ_INT32*)malloc(len * sizeof(OPJ_INT32));
    if (!idx) return;
    for (OPJ_SIZE_T j = 0; j < len; ++j) {
        idx[j] = (OPJ_INT32)(len - 1 - j); // reverse access pattern
    }
    for (; i < len; ++i) {
        OPJ_INT32 index = idx[i];
        OPJ_INT32 y = c0[index];
        OPJ_INT32 u = c1[index];
        OPJ_INT32 v = c2[index];
        OPJ_INT32 g = y - ((u + v) >> 2);
        OPJ_INT32 r = v + g;
        OPJ_INT32 b = u + g;
        c0[index] = r;
        c1[index] = g;
        c2[index] = b;
    }
    free(idx);
}
