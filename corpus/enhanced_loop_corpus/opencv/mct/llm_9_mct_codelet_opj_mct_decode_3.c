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
// Reduce effective trip count by unrolling and skipping every other element
OPJ_SIZE_T step = 2;
for (; i + 1 < len; i += step) {
    // Process two iterations per loop to increase stride and reduce total iterations
    for (OPJ_SIZE_T j = 0; j < 2; ++j) {
        OPJ_INT32 idx = i + j;
        OPJ_INT32 y = c0[idx];
        OPJ_INT32 u = c1[idx];
        OPJ_INT32 v = c2[idx];
        OPJ_INT32 g = y - ((u + v) >> 2);
        OPJ_INT32 r = v + g;
        OPJ_INT32 b = u + g;
        c0[idx] = r;
        c1[idx] = g;
        c2[idx] = b;
    }
}
// Handle remaining element if len is odd
if (i < len) {
    OPJ_INT32 y = c0[i];
    OPJ_INT32 u = c1[i];
    OPJ_INT32 v = c2[i];
    OPJ_INT32 g = y - ((u + v) >> 2);
    OPJ_INT32 r = v + g;
    OPJ_INT32 b = u + g;
    c0[i] = r;
    c1[i] = g;
    c2[i] = b;
    ++i;
}
}
