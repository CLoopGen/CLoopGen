#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

typedef uint32_t OPJ_UINT32;

extern OPJ_INT32 *a;
extern OPJ_INT32 i;
extern OPJ_UINT32 off;
extern OPJ_INT32 i_max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (; i < i_max; i++) {
    OPJ_INT32 base1 = (OPJ_INT32)(i) * 8;
    OPJ_INT32 base2_prev = (OPJ_INT32)(i - 1) * 8 + 4;
    OPJ_INT32 base2_curr = (OPJ_INT32)(i) * 8 + 4;
    OPJ_INT32 temp[4];
    for (off = 0; off < 4; off++) {
        temp[off] = (a[base2_prev + off] + a[base2_curr + off] + 2) >> 2;
    }
    for (off = 0; off < 4; off++) {
        a[base1 + off] -= temp[off];
    }
}
}
