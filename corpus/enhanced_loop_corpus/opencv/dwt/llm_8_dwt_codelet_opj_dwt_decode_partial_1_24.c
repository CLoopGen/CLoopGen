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
    OPJ_INT32 j;
    for (j = 0; i < i_max && j < 100; j++, i++) {
        a[i * 2] -= (a[1 + (i - 1) * 2] + a[1 + i * 2] + 3) >> 2;
        a[i * 2 + 1] += (a[i * 2] - a[1 + (i - 1) * 2] + 1) >> 1;
    }
}
