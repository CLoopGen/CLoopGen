#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

typedef uint32_t OPJ_UINT32;

extern OPJ_INT32 *a;
extern OPJ_INT32 sn;
extern OPJ_INT32 win_h_x1;
extern OPJ_INT32 i;
extern OPJ_UINT32 off;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; i < win_h_x1 && i < sn; i++) {
        OPJ_INT32 base_idx = (1 + (OPJ_UINT32)i * 2) * 4;
        for (off = 0; off < 4; off++) {
            OPJ_INT32 val1 = (i < sn) ? a[(OPJ_UINT32)i * 2 * 4 + off] : a[(OPJ_UINT32)(sn - 1) * 2 * 4 + off];
            OPJ_INT32 val2 = ((i + 1) >= sn) ? a[(OPJ_UINT32)(sn - 1) * 2 * 4 + off] : a[(OPJ_UINT32)(i + 1) * 2 * 4 + off];
            a[base_idx + off] += (val1 + val2) >> 1;
        }
    }
}
