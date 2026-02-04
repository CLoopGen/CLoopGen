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
    OPJ_UINT32 c1, c2;
    for (c1 = 0; c1 < 4; c1++) {
        for (c2 = 0; c2 < 2; c2++) {
            OPJ_UINT32 c = c1 * 2 + c2;
            tmp[((1 + i) * 2) * 8 + c] += (tmp[i * 2 * 8 + c] + tmp[i * 2 * 8 + c] + 2) >> 2;
        }
    }
}
