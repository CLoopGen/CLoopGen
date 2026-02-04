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



void loop() {
    for (; i < win_l_x1; i++) {
        OPJ_INT32 temp_val[4];
        // Introduce temporary storage to remove immediate write-read dependency (WAW and RAW)
        // Precompute the values that will be used in the update, breaking direct memory dependency
        for (off = 0; off < 4; off++) {
            OPJ_INT32 left_val, center_val;
            // Clamp index (i-1) safely
            left_val = (i - 1) < 0 ? 
                a[(1 + (OPJ_UINT32)(0) * 2) * 4 + off] : 
                ((i - 1) >= dn ? a[(1 + (OPJ_UINT32)(dn - 1) * 2) * 4 + off] : a[(1 + (OPJ_UINT32)(i - 1) * 2) * 4 + off]);
            // Current index clamping
            center_val = i < 0 ? 
                a[(1 + (OPJ_UINT32)(0) * 2) * 4 + off] : 
                (i >= dn ? a[(1 + (OPJ_UINT32)(dn - 1) * 2) * 4 + off] : a[(1 + (OPJ_UINT32)(i) * 2) * 4 + off]);

            temp_val[off] = (left_val + center_val + 2) >> 2;
        }
        // Now apply updates using precomputed values — removes intra-loop memory dependency
        for (off = 0; off < 4; off++) {
            a[(OPJ_UINT32)(i) * 2 * 4 + off] -= temp_val[off];
        }
    }
}
