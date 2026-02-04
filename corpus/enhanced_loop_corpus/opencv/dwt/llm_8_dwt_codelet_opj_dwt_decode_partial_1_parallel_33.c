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
    for (off = 0; off < 8; off += 2) {
        OPJ_INT32 temp = a[off];
        temp *= 3;
        temp += 5;
        a[off] = temp / 2;
    }
}
