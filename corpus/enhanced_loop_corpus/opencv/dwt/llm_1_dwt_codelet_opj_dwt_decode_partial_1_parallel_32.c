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
        for (OPJ_UINT32 outer_off = 0; outer_off < 2; outer_off++) {
            for (off = 0; off < 2; off++) {
                OPJ_UINT32 idx = (1 + (OPJ_UINT32)(i) * 2) * 4 + (outer_off * 2 + off);
                OPJ_INT32 val1 = (i < 0 ? a[(OPJ_UINT32)(0) * 2 * 4 + (outer_off * 2 + off)] :
                                (i >= sn ? a[(OPJ_UINT32)(sn - 1) * 2 * 4 + (outer_off * 2 + off)] :
                                         a[(OPJ_UINT32)(i) * 2 * 4 + (outer_off * 2 + off)]));
                OPJ_INT32 val2 = ((i + 1) < 0 ? a[(OPJ_UINT32)(0) * 2 * 4 + (outer_off * 2 + off)] :
                                 ((i + 1) >= sn ? a[(OPJ_UINT32)(sn - 1) * 2 * 4 + (outer_off * 2 + off)] :
                                                 a[(OPJ_UINT32)(i + 1) * 2 * 4 + (outer_off * 2 + off)]));
                a[idx] += (val1 + val2) >> 1;
            }
        }
    }
}
