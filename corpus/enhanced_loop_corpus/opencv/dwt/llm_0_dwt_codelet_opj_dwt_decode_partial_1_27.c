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
    OPJ_INT32 j;
    for (j = 0; j < 1; j++) {
        for (; i < win_h_x1; i++) {
            a[(1 + (i) * 2)] += (((i) < 0 ? a[(0) * 2] : ((i) >= sn ? a[(sn - 1) * 2] : a[(i) * 2])) + ((i + 1) < 0 ? a[(0) * 2] : ((i + 1) >= sn ? a[(sn - 1) * 2] : a[(i + 1) * 2]))) >> 1;
        }
    }
}
