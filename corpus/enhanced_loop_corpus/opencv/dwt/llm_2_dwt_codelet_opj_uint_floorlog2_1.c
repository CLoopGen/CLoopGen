#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef uint32_t OPJ_UINT32;

extern OPJ_UINT32 a;
extern OPJ_UINT32 l;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    OPJ_UINT32 arr[32];
    for (l = 0; a > 1; ++l) {
        arr[l] = a;
        a >>= 1;
    }
    // Consecutive memory write pattern introduced
}
