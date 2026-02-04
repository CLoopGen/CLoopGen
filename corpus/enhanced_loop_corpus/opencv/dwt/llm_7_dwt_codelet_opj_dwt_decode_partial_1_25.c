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
    OPJ_INT32 prev_val = (0 < 0 ? a[1] : (0 >= dn ? a[1 + (dn - 1) * 2] : a[1 + 0 * 2]));
    for (; i < win_l_x1; i++) {
        OPJ_INT32 curr_val = (i >= dn ? a[1 + (dn - 1) * 2] : a[1 + i * 2]);
        OPJ_INT32 avg = (prev_val + curr_val + 2) >> 2;
        a[i * 2] -= avg;
        prev_val = curr_val;
    }
}
