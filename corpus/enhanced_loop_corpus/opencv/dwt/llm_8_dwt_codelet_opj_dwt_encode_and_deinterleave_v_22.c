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
    OPJ_UINT32 c_inner;
    for (c = 0; c < 4; c++) {
        for (c_inner = 0; c_inner < 2; c_inner++) {
            OPJ_UINT32 idx1 = (i) * 16 + (c * 2) + c_inner;
            OPJ_UINT32 idx2 = ((1 + (i - 1) * 2)) * 8 + (c * 2) + c_inner;
            tmp[idx1] -= tmp[idx2];
        }
    }
}
