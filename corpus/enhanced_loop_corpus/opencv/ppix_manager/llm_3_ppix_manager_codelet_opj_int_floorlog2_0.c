#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

extern OPJ_INT32 a;
extern OPJ_INT32 l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    OPJ_INT32 *ptr;
    OPJ_INT32 buffer[8];
    ptr = buffer;
    for (l = 0; l < 8 && a > 1; l++) {
        *(ptr + l) = a;  // Consecutive write to memory locations via pointer arithmetic
        a >>= 1;
    }
    a = *(ptr);  // Ensure side effect on 'a' is preserved post-loop
}
