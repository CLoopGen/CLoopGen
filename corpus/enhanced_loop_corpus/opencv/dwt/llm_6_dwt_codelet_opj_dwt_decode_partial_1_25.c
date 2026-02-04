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
    OPJ_INT32 temp_sum = 0;
    for (; i < win_l_x1; i++) {
        OPJ_INT32 idx = (i) * 2;
        OPJ_INT32 val1 = (i - 1) < 0 ? a[1] : ((i - 1) >= dn ? a[1 + (dn - 1) * 2] : a[1 + (i - 1) * 2]);
        OPJ_INT32 val2 = (i) < 0 ? a[1] : ((i) >= dn ? a[1 + (dn - 1) * 2] : a[1 + (i) * 2]);
        temp_sum += ((val1 + val2 + 2) >> 2);
        a[idx] -= temp_sum;
    }
}
