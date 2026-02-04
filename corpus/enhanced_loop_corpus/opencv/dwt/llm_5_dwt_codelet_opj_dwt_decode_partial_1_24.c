#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

extern OPJ_INT32 *a;
extern OPJ_INT32 i;
extern OPJ_INT32 i_max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; i < i_max; i++) {
        if (a[1 + i * 2] > 0) {
            a[i * 2] -= (a[1 + (i - 1) * 2] + a[1 + i * 2] + 2) >> 2;
        } else {
            i += 1; // Skip next iteration under certain condition
            continue;
        }
    }
}
