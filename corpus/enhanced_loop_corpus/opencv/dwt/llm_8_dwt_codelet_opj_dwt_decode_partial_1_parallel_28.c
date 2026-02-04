#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

typedef uint32_t OPJ_UINT32;

extern OPJ_INT32 *a;
extern OPJ_INT32 dn;
extern OPJ_INT32 i;
extern OPJ_UINT32 off;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (off = 0; off < 8; off += 2) {
    OPJ_INT32 val1, val2;
    OPJ_UINT32 idx1 = (1 + (OPJ_UINT32)(i - 1) * 2) * 4 + off;
    OPJ_UINT32 idx2 = (1 + (OPJ_UINT32)(i) * 2) * 4 + off;

    if ((i - 1) < 0) val1 = a[(1 + (OPJ_UINT32)(0) * 2) * 4 + off];
    else if ((i - 1) >= dn) val1 = a[(1 + (OPJ_UINT32)(dn - 1) * 2) * 4 + off];
    else val1 = a[idx1];

    if (i < 0) val2 = a[(1 + (OPJ_UINT32)(0) * 2) * 4 + off];
    else if (i >= dn) val2 = a[(1 + (OPJ_UINT32)(dn - 1) * 2) * 4 + off];
    else val2 = a[idx2];

    a[(OPJ_UINT32)(i) * 2 * 4 + off] -= (val1 + val2 + 2) >> 2;
    if (off + 1 < 8) {
        a[(OPJ_UINT32)(i) * 2 * 4 + off + 1] -= (val1 + val2 + 2) >> 2;
    }
}
}
