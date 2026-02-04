#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

extern OPJ_INT32 a;
extern OPJ_INT32 l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    OPJ_INT32 temp_array[16];
    for (l = 0; a > 1 && l < 16; l++) {
        temp_array[l] = a;
        a >>= 1;
    }
    // Consecutive memory write pattern introduced via local array
}
