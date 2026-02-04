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
    OPJ_INT32 y = c0[i];
    OPJ_INT32 u = c1[i];
    OPJ_INT32 v = c2[i];
    OPJ_INT32 g = y - ((u + v) >> 2);
    OPJ_INT32 r = v + g;
    OPJ_INT32 b = u + g;
    // Increase arithmetic intensity with extra computations (e.g., simulate saturation)
    r = (r > 262143) ? 262143 : ((r < 0) ? 0 : r);
    g = (g > 262143) ? 262143 : ((g < 0) ? 0 : g);
    b = (b > 262143) ? 262143 : ((b < 0) ? 0 : b);
    c0[i] = r;
    c1[i] = g;
    c2[i] = b;
}
}
