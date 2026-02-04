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
for (; i < win_h_x1 && sn > 0; i += 2) {
    for (off = 0; off < 4; off += 2) {
        OPJ_UINT32 idx_i   = (OPJ_UINT32)(i) * 2 * 4 + off;
        OPJ_UINT32 idx_i1  = (OPJ_UINT32)(i + 1) * 2 * 4 + off;
        OPJ_UINT32 idx_ip1 = (OPJ_UINT32)(i) * 2 * 4 + off + 1;
        OPJ_UINT32 idx_i1p1= (OPJ_UINT32)(i + 1) * 2 * 4 + off + 1;

        OPJ_INT32 curr0 = (i < 0) ? a[(OPJ_UINT32)(0)*2*4+off] : 
                          ((i >= sn) ? a[(OPJ_UINT32)(sn-1)*2*4+off] : a[idx_i]);
        OPJ_INT32 next0 = (i+1 < 0) ? a[(OPJ_UINT32)(0)*2*4+off] : 
                          ((i+1 >= sn) ? a[(OPJ_UINT32)(sn-1)*2*4+off] : a[idx_i1]);

        OPJ_INT32 curr1 = ((i < 0 || off+1 >= 4) ? curr0 : 
                          ((i >= sn) ? a[(OPJ_UINT32)(sn-1)*2*4+off+1] : a[idx_ip1]));
        OPJ_INT32 next1 = ((i+1 < 0 || off+1 >= 4) ? next0 : 
                          ((i+1 >= sn) ? a[(OPJ_UINT32)(sn-1)*2*4+off+1] : a[idx_i1p1]));

        OPJ_INT32 avg0 = (curr0 + next0) >> 1;
        OPJ_INT32 avg1 = (curr1 + next1) >> 1;

        OPJ_UINT32 dst0 = (1 + (OPJ_UINT32)(i) * 2) * 4 + off;
        OPJ_UINT32 dst1 = (1 + (OPJ_UINT32)(i) * 2) * 4 + off + 1;

        a[dst0] += avg0;
        if (off + 1 < 4) {
            a[dst1] += avg1;
        }
    }
}
}
