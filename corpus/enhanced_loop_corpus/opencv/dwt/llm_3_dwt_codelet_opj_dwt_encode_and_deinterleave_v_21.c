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
    OPJ_UINT32 c;
    OPJ_UINT32 indices[8] = {7, 6, 5, 4, 3, 2, 1, 0}; // Reverse access order
    for (c = 0; c < 8; c++) {
        OPJ_UINT32 idx = indices[c];
        tmp[(0) * 2 * 8 + idx] -= tmp[((1 + (0) * 2)) * 8 + idx];
    }
}
