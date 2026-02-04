#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef uint32_t OPJ_UINT32;

extern OPJ_UINT32 a;
extern OPJ_UINT32 l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    OPJ_UINT32 temp = a;
    l = 0;
    for (OPJ_UINT32 shift = 1; shift <= 16; shift <<= 1) {
        if (temp > (1U << shift)) {
            temp >>= shift;
            l += shift;
        }
    }
    while (temp > 1) {
        temp >>= 1;
        ++l;
    }
    a = temp;
}
