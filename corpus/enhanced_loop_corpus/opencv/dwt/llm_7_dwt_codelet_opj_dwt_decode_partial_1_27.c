#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

extern OPJ_INT32 *a;
extern OPJ_INT32 sn;
extern OPJ_INT32 win_h_x1;
extern OPJ_INT32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    OPJ_INT32 prev_val, next_val, interpolated;
    for (; i < win_h_x1; i++) {
        OPJ_INT32 idx = i * 2;
        prev_val = (i < 0) ? a[0] : ((i >= sn) ? a[(sn - 1) * 2] : a[idx]);
        next_val = (i + 1 < 0) ? a[0] : ((i + 1 >= sn) ? a[(sn - 1) * 2] : a[(i + 1) * 2]);
        interpolated = (prev_val + next_val) >> 1;
        a[1 + idx] = interpolated; // WAW dependency removed: direct assignment instead of +=
    }
}
