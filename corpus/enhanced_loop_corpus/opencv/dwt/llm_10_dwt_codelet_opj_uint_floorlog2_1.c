#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef uint32_t OPJ_UINT32;

extern OPJ_UINT32 a;
extern OPJ_UINT32 l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    OPJ_UINT32 step = 4;
    OPJ_UINT32 limit = (OPJ_UINT32)16;
    for (l = 0; a > limit || (a > 1 && l % step == 0 && a <= limit); ++l) {
        if (a > limit) {
            a >>= step; // Coarse shift when large
        } else {
            a >>= 1; // Fine shift near end
        }
    }
}
