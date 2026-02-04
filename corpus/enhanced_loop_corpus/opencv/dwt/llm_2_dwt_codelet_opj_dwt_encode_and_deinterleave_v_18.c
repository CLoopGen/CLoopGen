#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

typedef uint32_t OPJ_UINT32;

extern OPJ_INT32 *restrict tmp;
extern OPJ_UINT32 c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by reordering computation to access adjacent elements
    OPJ_INT32 *base = &tmp[(0) * 2 * 8];
    OPJ_INT32 *src = &tmp[((1 + (0) * 2)) * 8];
    for (c = 0; c < 8; c++) {
        base[c] += (src[c] + src[c] + 2) >> 2;
    }
}
