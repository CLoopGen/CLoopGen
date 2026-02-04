#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

extern OPJ_INT32 a;
extern OPJ_INT32 l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    OPJ_INT32 temp = a;
    for (l = 0; temp > 1; l++) {
        temp >>= 1;
        a = temp; // Introduce WAW dependency: 'a' is written after prior write
    }
}
