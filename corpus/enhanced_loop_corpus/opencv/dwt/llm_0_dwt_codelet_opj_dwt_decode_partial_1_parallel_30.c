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
    for (off = 0; off < 4; off++) {
        OPJ_INT32 temp_val1, temp_val2;
        OPJ_UINT32 idx1 = (1 + (OPJ_UINT32)(i - 1) * 2) * 4 + off;
        OPJ_UINT32 idx2 = (1 + (OPJ_UINT32)(i) * 2) * 4 + off;

        temp_val1 = (i - 1) < 0 ? a[(1 + (OPJ_UINT32)(0) * 2) * 4 + off] : 
                    ((i - 1) >= dn ? a[(1 + (OPJ_UINT32)(dn - 1) * 2) * 4 + off] : a[idx1]);
        temp_val2 = (i) < 0 ? a[(1 + (OPJ_UINT32)(0) * 2) * 4 + off] : 
                    (i >= dn ? a[(1 + (OPJ_UINT32)(dn - 1) * 2) * 4 + off] : a[idx2]);

        a[(OPJ_UINT32)(i) * 2 * 4 + off] -= (temp_val1 + temp_val2 + 2) >> 2;
    }
}
}
