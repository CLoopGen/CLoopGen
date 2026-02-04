#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef uint32_t OPJ_UINT32;

extern OPJ_UINT32 a;
extern OPJ_UINT32 l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    OPJ_UINT32 mask = 1;
    l = 0;
    for (OPJ_UINT32 shift = 0; shift < a && a > 1; shift += 3) {
        a >>= 3;
        l++;
        mask <<= 3;
        if (mask >= a) break;
    }
    while ((a >> 1) > 1) {
        a >>= 1;
        l++;
    }
}
