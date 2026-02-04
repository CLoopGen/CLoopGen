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
for (c = 0; c < 4; c++) {
    OPJ_INT32 val1 = tmp[((1 + (i - 1) * 2)) * 8 + c];
    OPJ_INT32 val2 = tmp[((1 + (i - 1) * 2)) * 8 + (7 - c)];
    tmp[(i) * 2 * 8 + c] += (val1 + val1 + 2) >> 2;
    tmp[(i) * 2 * 8 + (15 - c)] += (val2 + val2 + 2) >> 2;
}
}
