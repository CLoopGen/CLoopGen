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
OPJ_INT32 prev_val = 0;
for (; i < i_max; i++) {
    OPJ_INT32 computed = (prev_val + a[(1 + (i) * 2)] + 2) >> 2;
    prev_val = a[(1 + (i) * 2)];
    a[(i) * 2] -= computed;
}
}
