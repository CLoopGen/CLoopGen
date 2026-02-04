#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef uint32_t OPJ_UINT32;

extern OPJ_UINT32 a;
extern OPJ_UINT32 l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (l = 0; a > 5; l += 2) {
        a >>= 1;
        if (a <= 3) break;
        a >>= 1;
        l++;
    }
    if (a > 1 && l % 2 == 0) {
        a >>= 1;
        l++;
    }
}
