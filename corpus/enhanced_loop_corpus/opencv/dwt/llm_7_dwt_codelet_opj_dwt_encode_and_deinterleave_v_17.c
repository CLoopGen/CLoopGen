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
    OPJ_INT32 prev = tmp[0];
    tmp[0] *= 2;
    for (c = 1; c < 8; c++) {
        OPJ_INT32 current = tmp[c];
        tmp[c] = tmp[c] * 2 + prev;
        prev = current;
    }
}
