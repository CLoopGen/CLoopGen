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
    OPJ_UINT32 outer_c;
    for (outer_c = 0; outer_c < 2; ++outer_c) {
        for (c = 0; c < 8; c++) {
            tmp[(0) * 2 * 8 + c] += (tmp[((1 + (0) * 2)) * 8 + c] + tmp[((1 + (0) * 2)) * 8 + c] + 2) >> 2;
        }
    }
}
