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
    OPJ_UINT32 c;
    for (c = 0; c < 8; c++) {
        OPJ_INT32 temp_val = (tmp[i * 2 * 8 + c] + tmp[i * 2 * 8 + c] + 2) >> 2;
        tmp[(1 + i * 2) * 8 + c] += temp_val;
    }
}
