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
for (c = 0; c < 16; c += 2) {
    OPJ_INT32 val = tmp[((1 + (0) * 2)) * 8 + c] + tmp[((1 + (0) * 2)) * 8 + c] + 3;
    tmp[(0) * 2 * 8 + c] += (val + (val >> 1) + 4) >> 3;
}
}
