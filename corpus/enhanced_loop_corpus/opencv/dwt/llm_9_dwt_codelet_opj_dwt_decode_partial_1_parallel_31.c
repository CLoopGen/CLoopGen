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
for (; i < i_max - 1; i += 2) {
    for (off = 0; off < 8; off++) {
        OPJ_UINT32 idx1 = (1 + (OPJ_UINT32)(i) * 2) * 4 + off;
        OPJ_UINT32 idx2 = (OPJ_UINT32)(i) * 2 * 4 + off;
        OPJ_UINT32 idx3 = (OPJ_UINT32)(i + 1) * 2 * 4 + off;
        a[idx1] += (a[idx2] + a[idx3]) >> 1;
        if (off < 4 && i + 1 < i_max) {
            OPJ_UINT32 idx1_next = (1 + (OPJ_UINT32)(i + 1) * 2) * 4 + off;
            OPJ_UINT32 idx2_next = (OPJ_UINT32)(i + 1) * 2 * 4 + off;
            OPJ_UINT32 idx3_next = (OPJ_UINT32)(i + 2) * 2 * 4 + off;
            a[idx1_next] += (a[idx2_next] + a[idx3_next]) >> 1;
        }
    }
}
}
