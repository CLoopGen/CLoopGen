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
OPJ_INT32 prev_accum[4] = {0};
for (; i < win_h_x1; i++) {
    for (off = 0; off < 4; off++) {
        OPJ_INT32 val_cur = (i < 0) ? a[(OPJ_UINT32)(0) * 2 * 4 + off] : 
                            ((i >= sn) ? a[(OPJ_UINT32)(sn - 1) * 2 * 4 + off] : a[(OPJ_UINT32)(i) * 2 * 4 + off]);
        OPJ_INT32 val_next = (i + 1 < 0) ? a[(OPJ_UINT32)(0) * 2 * 4 + off] : 
                             ((i + 1 >= sn) ? a[(OPJ_UINT32)(sn - 1) * 2 * 4 + off] : a[(OPJ_UINT32)(i + 1) * 2 * 4 + off]);
        OPJ_INT32 avg = (val_cur + val_next) >> 1;
        
        if (i > 0) {
            a[(1 + (OPJ_UINT32)(i) * 2) * 4 + off] += avg + prev_accum[off];
        } else {
            a[(1 + (OPJ_UINT32)(i) * 2) * 4 + off] += avg;
        }
        prev_accum[off] = avg;
    }
}
}
