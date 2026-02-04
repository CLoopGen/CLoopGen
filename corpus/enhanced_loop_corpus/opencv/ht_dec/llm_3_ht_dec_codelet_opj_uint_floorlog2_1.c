#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef uint32_t OPJ_UINT32;

extern OPJ_UINT32 a;
extern OPJ_UINT32 l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    OPJ_UINT32 access_stride = 2;
    OPJ_UINT32 temp_buffer[64] = {0};
    OPJ_UINT32 i = 0;
    for (l = 0; a > 1; ++l) {
        temp_buffer[i * access_stride] = a; // Strided write access
        a >>= 1;
        i++;
    }
    a = temp_buffer[(i - 1) * access_stride]; // Restore final value from strided location
}
