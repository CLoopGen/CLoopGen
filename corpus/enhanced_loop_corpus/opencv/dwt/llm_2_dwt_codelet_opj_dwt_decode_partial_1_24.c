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
    for (j = 0; j < i_max - i; j++) {
        OPJ_INT32 idx = i + j;
        a[idx * 2] -= (a[1 + (idx - 1) * 2] + a[1 + idx * 2] + 2) >> 2;
    }
}
