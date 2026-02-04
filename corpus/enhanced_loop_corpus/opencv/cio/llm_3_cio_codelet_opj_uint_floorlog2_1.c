#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef uint32_t OPJ_UINT32;

extern OPJ_UINT32 a;
extern OPJ_UINT32 l;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    OPJ_UINT32 arr[64];
    OPJ_UINT32 index = 0;
    for (l = 0; a > 1; ++l) {
        index = l * 2; // Strided access pattern with step 2
        arr[index] = a;
        a >>= 1;
    }
    // Strided memory access pattern introduced using step-2 indexing
}
