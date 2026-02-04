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
    if (i == 0) continue;
    for (off = 0; off < 4; off++) {
        a[(OPJ_UINT32)(i) * 8 + off] -= (a[(1 + (OPJ_UINT32)(i - 1) * 2) * 4 + off] + a[(1 + (OPJ_UINT32)(i) * 2) * 4 + off] + 2) >> 2;
    }
}
}
