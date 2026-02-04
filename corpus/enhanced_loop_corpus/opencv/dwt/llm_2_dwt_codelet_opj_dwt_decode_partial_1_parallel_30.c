#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

typedef uint32_t OPJ_UINT32;

extern OPJ_INT32 *a;
extern OPJ_INT32 dn;
extern OPJ_INT32 win_l_x1;
extern OPJ_INT32 i;
extern OPJ_UINT32 off;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (; i < win_l_x1; i++) {
    OPJ_INT32 base_idx = (OPJ_INT32)(i * 8);
    for (off = 0; off < 4; off++) {
        OPJ_UINT32 addr = base_idx + off;
        OPJ_INT32 val1, val2;
        OPJ_INT32 idx1 = i - 1;
        OPJ_INT32 idx2 = i;

        // Clamp indices to valid range [0, dn-1]
        idx1 = (idx1 < 0) ? 0 : ((idx1 >= dn) ? (dn - 1) : idx1);
        idx2 = (idx2 < 0) ? 0 : ((idx2 >= dn) ? (dn - 1) : idx2);

        OPJ_UINT32 src1 = (1 + (OPJ_UINT32)(idx1) * 2) * 4 + off;
        OPJ_UINT32 src2 = (1 + (OPJ_UINT32)(idx2) * 2) * 4 + off;

        val1 = a[src1];
        val2 = a[src2];

        a[addr] -= (val1 + val2 + 2) >> 2;
    }
}
}
