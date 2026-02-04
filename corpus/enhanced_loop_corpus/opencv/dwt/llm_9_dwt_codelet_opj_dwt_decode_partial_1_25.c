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
OPJ_INT32 j;
for (j = i; j < win_l_x1 && j < i + 4; j++) {
    OPJ_INT32 val1 = (j - 1) < 0 ? a[(1 + (0) * 2)] : ((j - 1) >= dn ? a[(1 + (dn - 1) * 2)] : a[(1 + (j - 1) * 2)]);
    OPJ_INT32 val2 = (j) < 0 ? a[(1 + (0) * 2)] : ((j) >= dn ? a[(1 + (dn - 1) * 2)] : a[(1 + (j) * 2)]);
    OPJ_INT32 avg = (val1 + val2 + 2) >> 2;
    a[(j) * 2] -= avg;
}
i = (win_l_x1 < i + 4) ? win_l_x1 : i + 4;
}
