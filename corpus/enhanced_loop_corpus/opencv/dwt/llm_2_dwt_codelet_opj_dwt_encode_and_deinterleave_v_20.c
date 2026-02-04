#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

typedef uint32_t OPJ_UINT32;

extern OPJ_INT32 *restrict tmp;
extern OPJ_UINT32 c;
extern OPJ_UINT32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by reordering computation to access adjacent elements
    OPJ_INT32 *base1 = &tmp[(i) * 16];        // Base pointer for tmp[i * 2 * 8 + c]
    OPJ_INT32 *base2 = &tmp[(1 + (i - 1) * 2) * 8]; // Base pointer for tmp[(1 + (i-1)*2)*8 + c]

    for (c = 0; c < 8; c++) {
        base1[c] += (base2[c] + base2[c] + 2) >> 2;
    }
}
