#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef uint32_t OPJ_UINT32;

extern OPJ_UINT32 a;
extern OPJ_UINT32 l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    OPJ_UINT32 stride = 2;
    OPJ_UINT32 access_index = 0;
    OPJ_UINT32 history[64];
    for (l = 0; a > 1; ++l) {
        history[access_index] = a;
        a >>= 1;
        access_index += stride; // Strided memory access pattern
    }
}
