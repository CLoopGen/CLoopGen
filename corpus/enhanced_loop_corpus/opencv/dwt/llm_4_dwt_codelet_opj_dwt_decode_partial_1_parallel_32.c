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
    for (; i < win_h_x1; i++) {
        if (i >= sn) continue;
        for (off = 0; off < 4; off++) {
            OPJ_INT32 val1, val2;
            OPJ_UINT32 idx1 = (OPJ_UINT32)(i) * 2 * 4 + off;
            OPJ_UINT32 idx2 = (OPJ_UINT32)(i + 1) * 2 * 4 + off;

            if (i < 0) {
                val1 = a[(OPJ_UINT32)(0) * 2 * 4 + off];
            } else if (i >= sn) {
                val1 = a[(OPJ_UINT32)(sn - 1) * 2 * 4 + off];
            } else {
                val1 = a[idx1];
            }

            if ((i + 1) < 0) {
                val2 = a[(OPJ_UINT32)(0) * 2 * 4 + off];
            } else if ((i + 1) >= sn) {
                val2 = a[(OPJ_UINT32)(sn - 1) * 2 * 4 + off];
            } else {
                val2 = a[idx2];
            }

            a[(1 + (OPJ_UINT32)(i) * 2) * 4 + off] += (val1 + val2) >> 1;
        }
    }
}
