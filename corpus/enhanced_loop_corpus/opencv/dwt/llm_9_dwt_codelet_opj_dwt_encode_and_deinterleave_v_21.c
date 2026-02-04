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
    for (c = 0; c < 4; c++) {
        OPJ_INT32 val1 = tmp[(0) * 2 * 8 + c];
        OPJ_INT32 val2 = tmp[((1 + (0) * 2)) * 8 + c];
        OPJ_INT32 val3 = tmp[(0) * 2 * 8 + c + 4];
        OPJ_INT32 val4 = tmp[((1 + (0) * 2)) * 8 + c + 4];
        tmp[(0) * 2 * 8 + c] = val1 - val2;
        tmp[(0) * 2 * 8 + c + 4] = val3 - val4;
    }
}
