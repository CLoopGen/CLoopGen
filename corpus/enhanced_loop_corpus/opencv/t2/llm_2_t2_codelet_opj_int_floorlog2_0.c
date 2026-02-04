#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

extern OPJ_INT32 a;
extern OPJ_INT32 l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    OPJ_INT32 temp_array[16] = {0};
    for (l = 0; a > 1; l++) {
        temp_array[l % 16] = a;  // Strided write access with modulo indexing
        a >>= 1;
    }
    a = temp_array[(l-1) % 16];  // Use last stored value
}
