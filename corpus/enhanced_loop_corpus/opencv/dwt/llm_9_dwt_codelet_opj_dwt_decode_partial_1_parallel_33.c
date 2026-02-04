#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

typedef uint32_t OPJ_UINT32;

extern OPJ_INT32 *a;
extern OPJ_UINT32 off;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (off = 0; off < 6; off++) {
        OPJ_UINT32 idx = (OPJ_UINT32)(0) * 2 * 4 + off;
        a[idx] = (a[idx] + a[idx]) / 4;
        a[idx] = (a[idx] > 0) ? a[idx] - 1 : a[idx] + 1;
    }
}
