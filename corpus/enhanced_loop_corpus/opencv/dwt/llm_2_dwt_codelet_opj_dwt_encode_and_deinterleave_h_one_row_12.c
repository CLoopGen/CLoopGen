#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

extern OPJ_INT32 *restrict row;
extern OPJ_INT32 *restrict tmp;
extern  OPJ_INT32 sn;
extern OPJ_INT32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern
    // Instead of accessing row with stride 2, precompute a strided view into consecutive elements
    OPJ_INT32 *restrict r = row;
    OPJ_INT32 *restrict t = tmp + sn;
    for (i = 0; i < sn - 1; i++) {
        t[i] = r[2*i + 1] - ((r[2*i] + r[2*i + 2]) >> 1);
    }
}
