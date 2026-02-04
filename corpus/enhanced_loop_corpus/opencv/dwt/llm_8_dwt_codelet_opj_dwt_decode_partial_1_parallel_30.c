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
    OPJ_INT32 base_idx = (OPJ_INT32)(i) * 8;
    for (off = 0; off < 4; off += 2) {
        OPJ_UINT32 idx1 = base_idx + off;
        OPJ_UINT32 src_idx_prev = (i - 1) < 0 ? (1 + 0U * 2) * 4 + off : 
                                  (i - 1) >= dn ? (1 + (OPJ_UINT32)(dn - 1) * 2) * 4 + off : 
                                  (1 + (OPJ_UINT32)(i - 1) * 2) * 4 + off;
        OPJ_UINT32 src_idx_curr = (i) < 0 ? (1 + 0U * 2) * 4 + off : 
                                  (i) >= dn ? (1 + (OPJ_UINT32)(dn - 1) * 2) * 4 + off : 
                                  (1 + (OPJ_UINT32)(i) * 2) * 4 + off;
        OPJ_INT32 avg = ((a[src_idx_prev] + a[src_idx_curr]) >> 1) + 1;
        a[idx1] -= avg;
        if (off + 1 < 4) {
            src_idx_prev = (i - 1) < 0 ? (1 + 0U * 2) * 4 + off + 1 : 
                           (i - 1) >= dn ? (1 + (OPJ_UINT32)(dn - 1) * 2) * 4 + off + 1 : 
                           (1 + (OPJ_UINT32)(i - 1) * 2) * 4 + off + 1;
            src_idx_curr = (i) < 0 ? (1 + 0U * 2) * 4 + off + 1 : 
                           (i) >= dn ? (1 + (OPJ_UINT32)(dn - 1) * 2) * 4 + off + 1 : 
                           (1 + (OPJ_UINT32)(i) * 2) * 4 + off + 1;
            avg = ((a[src_idx_prev] + a[src_idx_curr]) >> 1) + 1;
            a[idx1 + 1] -= avg;
        }
    }
}
}
