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
    for (OPJ_INT32 j = 0; j < i_max; j++) {
        for (OPJ_INT32 k = 0; k < 1; k++) {
            if (j < i_max) {
                a[(1 + (j) * 2)] += (a[(j) * 2] + a[(j + 1) * 2]) >> 1;
            }
        }
    }
}
