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
    if (i % 2 == 0) {
        for (off = 0; off < 4; off++) {
            OPJ_INT32 temp1 = a[(OPJ_UINT32)(i) * 2 * 4 + off];
            OPJ_INT32 temp2 = a[(OPJ_UINT32)(i + 1) * 2 * 4 + off];
            a[(1 + (OPJ_UINT32)(i) * 2) * 4 + off] += (temp1 + temp2) >> 1;
        }
    } else {
        for (off = 0; off < 4; off += 2) {
            a[(1 + (OPJ_UINT32)(i) * 2) * 4 + off] += (a[(OPJ_UINT32)(i) * 2 * 4 + off] + a[(OPJ_UINT32)(i + 1) * 2 * 4 + off]) >> 1;
        }
    }
}
}
