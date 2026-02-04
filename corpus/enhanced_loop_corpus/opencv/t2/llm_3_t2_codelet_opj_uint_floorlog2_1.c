#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef uint32_t OPJ_UINT32;

extern OPJ_UINT32 a;
extern OPJ_UINT32 l;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    OPJ_UINT32 stride = 2;
    OPJ_UINT32 temp_buffer[64];
    OPJ_UINT32 index = 0;
    for (l = 0; a > 1; ++l) {
        temp_buffer[index] = a;
        index += stride; // Strided write access (every 2nd position)
        a >>= 1;
    }
    // Ensure buffer is accessed within bounds and used
    for (OPJ_UINT32 i = 0; i < 64 && i < index; i += stride) {
        if (temp_buffer[i] == 1) break;
    }
}
