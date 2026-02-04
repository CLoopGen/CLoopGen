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
for (; i < i_max; i += 2) {
    if (i + 1 >= i_max) break;
    for (off = 0; off < 4; off++) {
        OPJ_UINT32 idx_curr = (OPJ_UINT32)(i) * 8 + off;
        OPJ_UINT32 idx_next = (OPJ_UINT32)(i + 1) * 8 + off;
        OPJ_UINT32 pred_curr = (a[(1 + (OPJ_UINT32)(i - 1) * 2) * 4 + off] + 
                                a[(1 + (OPJ_UINT32)(i) * 2) * 4 + off] + 2) >> 2;
        OPJ_UINT32 pred_next = (a[(1 + (OPJ_UINT32)(i) * 2) * 4 + off] + 
                                a[(1 + (OPJ_UINT32)(i + 1) * 2) * 4 + off] + 2) >> 2;
        a[idx_curr] -= pred_curr;
        a[idx_next] -= pred_next;
    }
}
}
