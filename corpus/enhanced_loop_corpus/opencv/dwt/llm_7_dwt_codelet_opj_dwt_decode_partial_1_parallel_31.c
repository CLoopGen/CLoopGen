#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

typedef uint32_t OPJ_UINT32;

extern OPJ_INT32 *a;
extern OPJ_INT32 i;
extern OPJ_UINT32 off;
extern OPJ_INT32 i_max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
OPJ_INT32 local_a[8] = {0};
for (; i < i_max; i++) {
    OPJ_UINT32 idx0 = (OPJ_UINT32)(i) * 2 * 4;
    OPJ_UINT32 idx1 = (OPJ_UINT32)(i + 1) * 2 * 4;
    OPJ_UINT32 out_idx = (1 + (OPJ_UINT32)(i) * 2) * 4;
    for (off = 0; off < 4; off++) {
        local_a[off] = a[idx0 + off];
        local_a[off + 4] = a[idx1 + off];
    }
    for (off = 0; off < 4; off++) {
        a[out_idx + off] += (local_a[off] + local_a[off + 4]) >> 1;
    }
}
}
