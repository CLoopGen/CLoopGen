#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef uint32_t OPJ_UINT32;

extern OPJ_UINT32 a;
extern OPJ_UINT32 l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    OPJ_UINT32 i;
    l = 0;
    for (i = 0; i < a && a > 1; i += 3) {  // Increase loop stride and tie trip count to original 'a'
        a >>= 1;
        l += 2;  // Artificially increase computational load per iteration
        a -= (a > 2);  // Additional arithmetic operation to increase complexity
    }
}
