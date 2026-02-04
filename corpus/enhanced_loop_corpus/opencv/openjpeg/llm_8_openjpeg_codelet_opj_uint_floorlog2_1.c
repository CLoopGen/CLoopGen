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
    for (; temp > 1; ++l) {
        temp >>= 2;  // Shift by 2 bits per iteration to reduce trip count and increase computational stride
        if (temp == 0) break;
    }
}
