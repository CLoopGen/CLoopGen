#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

extern OPJ_INT32 *a;
extern OPJ_INT32 dn;
extern OPJ_INT32 win_l_x1;
extern OPJ_INT32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (; i < win_l_x1; i++) {
    OPJ_INT32 idx = i * 2;
    OPJ_INT32 prev_idx = (i - 1) < 0 ? 0 : (i - 1) >= dn ? dn - 1 : i - 1;
    OPJ_INT32 curr_idx = i >= dn ? dn - 1 : i;
    OPJ_INT32 val_prev = a[1 + prev_idx * 2];
    OPJ_INT32 val_curr = a[1 + curr_idx * 2];
    a[idx] -= (val_prev + val_curr + 2) >> 2;
}
}
