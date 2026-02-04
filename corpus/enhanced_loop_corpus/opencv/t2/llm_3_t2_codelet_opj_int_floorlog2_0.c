#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

extern OPJ_INT32 a;
extern OPJ_INT32 l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    OPJ_INT32 access_pattern[] = {0, 2, 4, 6, 8, 10, 12, 14, 1, 3, 5, 7, 9, 11, 13, 15};
    OPJ_INT32 temp_buffer[16] = {0};
    for (l = 0; a > 1 && l < 16; l++) {
        temp_buffer[access_pattern[l]] = a;  // Indirect (random-like) access pattern
        a >>= 1;
    }
    a = temp_buffer[access_pattern[l > 0 ? l - 1 : 0]];
}
