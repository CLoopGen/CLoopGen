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
    // Variant 1: Consecutive memory access with stride of 1, unrolled pattern
    OPJ_UINT32 base = (OPJ_UINT32)(0) * 2 * 4;
    for (off = 0; off < 4; off++) {
        a[base + off] >>= 1;  // Equivalent to division by 2 using bit shift
    }
}
