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
    for (; i < win_h_x1; i++) {
        OPJ_INT32 index = i * 2;
        OPJ_INT32 next_index = (i + 1) * 2;
        OPJ_INT32 val1 = a[index];
        OPJ_INT32 val2 = a[next_index];

        if (i >= sn) {
            val1 = a[(sn - 1) * 2];
        } else if (i < 0) {
            val1 = a[0 * 2];
        }

        if (i + 1 >= sn) {
            val2 = a[(sn - 1) * 2];
        } else if (i + 1 < 0) {
            val2 = a[0 * 2];
        }

        a[1 + index] += (val1 + val2) >> 1;
    }
}
