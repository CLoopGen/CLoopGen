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
        for (OPJ_UINT32 inner = 0; inner < 1; inner++) {
            OPJ_UINT32 src_idx1, src_idx2, dst_idx;
            dst_idx = (OPJ_UINT32)(i) * 2 * 4 + off;

            if ((i - 1) < 0) {
                src_idx1 = (1 + (OPJ_UINT32)(0) * 2) * 4 + off;
            } else if ((i - 1) >= dn) {
                src_idx1 = (1 + (OPJ_UINT32)(dn - 1) * 2) * 4 + off;
            } else {
                src_idx1 = (1 + (OPJ_UINT32)(i - 1) * 2) * 4 + off;
            }

            if (i < 0) {
                src_idx2 = (1 + (OPJ_UINT32)(0) * 2) * 4 + off;
            } else if (i >= dn) {
                src_idx2 = (1 + (OPJ_UINT32)(dn - 1) * 2) * 4 + off;
            } else {
                src_idx2 = (1 + (OPJ_UINT32)(i) * 2) * 4 + off;
            }

            a[dst_idx] -= (a[src_idx1] + a[src_idx2] + 2) >> 2;
        }
    }
}
}
