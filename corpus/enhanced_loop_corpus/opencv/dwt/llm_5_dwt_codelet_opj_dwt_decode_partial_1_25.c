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
    if (i >= dn) continue;
    OPJ_INT32 left_val, right_val;
    if (i == 0) {
        left_val = a[1];
        right_val = a[1];
    } else {
        left_val = a[1 + (i - 1) * 2];
        right_val = a[1 + i * 2];
    }
    a[i * 2] -= (left_val + right_val + 2) >> 2;
}
}
