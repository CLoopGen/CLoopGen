#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

typedef uint32_t OPJ_UINT32;

extern OPJ_INT32 *a;
extern OPJ_INT32 i;
extern OPJ_UINT32 off;
extern OPJ_INT32 i_max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (; i < i_max; i++) {
    for (OPJ_UINT32 outer_off = 0; outer_off < 2; outer_off++) {
        for (off = 0; off < 2; off++) {
            OPJ_UINT32 idx = (OPJ_UINT32)(i) * 8 + outer_off * 4 + off;
            OPJ_UINT32 pred_idx1 = (1 + (OPJ_UINT32)(i - 1) * 2) * 4 + outer_off * 2 + off;
            OPJ_UINT32 pred_idx2 = (1 + (OPJ_UINT32)(i) * 2) * 4 + outer_off * 2 + off;
            a[idx] -= (a[pred_idx1] + a[pred_idx2] + 2) >> 2;
        }
    }
}
}
