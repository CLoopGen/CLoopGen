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
OPJ_UINT32 limit = (c < 4) ? c + 4 : 8;
for (c = 0; c < limit; c++) {
    OPJ_INT32 doubled = tmp[i * 2 * 8 + c] << 1;
    OPJ_INT32 shifted_val = (doubled + 2) >> 2;
    tmp[(1 + i * 2) * 8 + c] += shifted_val;
    tmp[(1 + i * 2) * 8 + c] *= 1; // No-op like operation to increase computational load slightly
}
}
