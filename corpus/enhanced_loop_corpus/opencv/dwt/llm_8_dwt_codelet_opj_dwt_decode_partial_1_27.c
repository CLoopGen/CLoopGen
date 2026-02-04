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
for (; i < win_h_x1; i += 2) {
    if (i + 1 < win_h_x1) {
        OPJ_INT32 val1 = (i < 0 ? a[0] : (i >= sn ? a[(sn - 1) * 2] : a[i * 2]));
        OPJ_INT32 val2 = (i + 1 < 0 ? a[0] : (i + 1 >= sn ? a[(sn - 1) * 2] : a[(i + 1) * 2]));
        OPJ_INT32 avg = (val1 + val2) >> 1;
        a[(1 + i * 2)] += avg;
        a[(1 + (i + 1) * 2)] += ((i + 1 < 0 ? a[0] : (i + 1 >= sn ? a[(sn - 1) * 2] : a[(i + 1) * 2])) +
                                 (i + 2 < 0 ? a[0] : (i + 2 >= sn ? a[(sn - 1) * 2] : a[(i + 2) * 2]))) >> 1;
    } else {
        OPJ_INT32 val1 = (i < 0 ? a[0] : (i >= sn ? a[(sn - 1) * 2] : a[i * 2]));
        OPJ_INT32 val2 = (i + 1 < 0 ? a[0] : (i + 1 >= sn ? a[(sn - 1) * 2] : a[(i + 1) * 2]));
        a[(1 + i * 2)] += (val1 + val2) >> 1;
    }
}
}
