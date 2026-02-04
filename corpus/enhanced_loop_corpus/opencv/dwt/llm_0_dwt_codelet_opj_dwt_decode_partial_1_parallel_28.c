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
    for (off = 0; off < 4; off++) {
        for (OPJ_UINT32 inner = 0; inner < 1; inner++) {
            a[(OPJ_UINT32)(i) * 2 * 4 + off] -= (((i - 1) < 0 ? a[(1 + (OPJ_UINT32)(0) * 2) * 4 + off] : ((i - 1) >= dn ? a[(1 + (OPJ_UINT32)(dn - 1) * 2) * 4 + off] : a[(1 + (OPJ_UINT32)(i - 1) * 2) * 4 + off])) + ((i) < 0 ? a[(1 + (OPJ_UINT32)(0) * 2) * 4 + off] : ((i) >= dn ? a[(1 + (OPJ_UINT32)(dn - 1) * 2) * 4 + off] : a[(1 + (OPJ_UINT32)(i) * 2) * 4 + off])) + 2) >> 2;
        }
    }
}
