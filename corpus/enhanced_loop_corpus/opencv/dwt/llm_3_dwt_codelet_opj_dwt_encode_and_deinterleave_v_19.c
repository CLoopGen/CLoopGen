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
    // Variant 2: Strided memory access with increased stride (access every 2nd element, unrolled-like pattern)
    OPJ_UINT32 stride = 2;
    OPJ_UINT32 limit = 8;
    for (c = 0; c < limit; c += stride) {
        tmp[((1 + i) * 2) * 8 + c] -= tmp[i * 2 * 8 + c];
        if (c + 1 < limit) {
            tmp[((1 + i) * 2) * 8 + c + 1] -= tmp[i * 2 * 8 + c + 1];
        }
    }
}
