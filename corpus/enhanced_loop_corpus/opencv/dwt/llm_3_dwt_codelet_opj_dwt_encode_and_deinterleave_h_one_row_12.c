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
    // Variant 2: Strided write and reordered read with step access
    // Write to tmp with negative stride and access row in non-linear but valid strided pattern
    OPJ_INT32 *restrict r = row;
    OPJ_INT32 *restrict t = tmp;
    OPJ_INT32 stride_offset = sn + sn - 2; // Starting from end of tmp[sn + i] region backwards
    for (i = 0; i < sn - 1; i++) {
        t[stride_offset - i] = r[2*i + 1] - ((r[i*2] + r[(i+1)*2]) >> 1);
    }
}
