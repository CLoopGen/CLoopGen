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
    OPJ_INT32 temp = (a[(1 + (i - 1) * 2)] + a[(1 + (i) * 2)] + 2) >> 2;
    a[(i) * 2] -= temp;
}
}
