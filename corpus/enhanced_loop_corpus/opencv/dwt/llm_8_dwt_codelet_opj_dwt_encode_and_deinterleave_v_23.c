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
for (c = 0; c < 16; c += 2) {
    OPJ_INT32 val = tmp[i * 2 * 8 + c] + tmp[i * 2 * 8 + c] + 2;
    tmp[(1 + i * 2) * 8 + c] += val >> 2;
    if (c + 1 < 8) {
        OPJ_INT32 val_next = tmp[i * 2 * 8 + c + 1] + tmp[i * 2 * 8 + c + 1] + 2;
        tmp[(1 + i * 2) * 8 + c + 1] += val_next >> 2;
    }
}
}
