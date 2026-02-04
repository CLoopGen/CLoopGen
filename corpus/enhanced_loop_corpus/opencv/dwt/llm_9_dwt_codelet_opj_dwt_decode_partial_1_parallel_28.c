#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

typedef uint32_t OPJ_UINT32;

extern OPJ_INT32 *a;
extern OPJ_INT32 dn;
extern OPJ_INT32 i;
extern OPJ_UINT32 off;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (off = 0; off < 2; off++) {
    OPJ_UINT32 base_idx = (OPJ_UINT32)(i) * 8 + off;
    OPJ_INT32 neighbor_val;

    if (i <= 0) {
        neighbor_val = a[(1 + (OPJ_UINT32)(0) * 2) * 4 + off];
    } else if (i >= dn) {
        neighbor_val = a[(1 + (OPJ_UINT32)(dn - 1) * 2) * 4 + off];
    } else {
        neighbor_val = a[(1 + (OPJ_UINT32)(i - 1) * 2) * 4 + off];
    }

    OPJ_INT32 current_val = (i >= 0 && i < dn) ? 
        a[(1 + (OPJ_UINT32)(i) * 2) * 4 + off] : 
        a[(1 + (OPJ_UINT32)(dn - 1) * 2) * 4 + off];

    a[base_idx] -= (neighbor_val + current_val + 2) >> 2;
    a[base_idx + 2] -= (current_val + current_val + 2) >> 2;
    a[base_idx + 4] -= (neighbor_val + neighbor_val + 2) >> 2;
    a[base_idx + 6] -= (neighbor_val + current_val + 1) >> 1;
}
}
