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
    OPJ_INT32 idx_i = (i >= dn) ? dn - 1 : (i < 0 ? 0 : i);
    for (off = 0; off < 4; off++) {
        OPJ_INT32 val_prev = ((i - 1) < 0) ? 0 : ((i - 1) >= dn) ? dn - 1 : i - 1;
        OPJ_UINT32 addr_prev = (1 + (OPJ_UINT32)(val_prev) * 2) * 4 + off;
        OPJ_UINT32 addr_curr = (1 + (OPJ_UINT32)(idx_i) * 2) * 4 + off;
        OPJ_INT32 avg = (a[addr_prev] + a[addr_curr] + 2) >> 2;
        a[(OPJ_UINT32)(i) * 2 * 4 + off] -= avg;
    }
}
}
