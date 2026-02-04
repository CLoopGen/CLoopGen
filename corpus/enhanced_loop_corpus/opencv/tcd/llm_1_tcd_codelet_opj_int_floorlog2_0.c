#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

extern OPJ_INT32 a;
extern OPJ_INT32 l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (l = 0; a > 1; l++) {
    a >>= 1;
    if ((a & 1) == 0) {
        for (OPJ_INT32 inner = 0; inner < 1; inner++) {
            // Dummy nested operation to increase nesting depth
            a >>= inner;
        }
    }
}
}
