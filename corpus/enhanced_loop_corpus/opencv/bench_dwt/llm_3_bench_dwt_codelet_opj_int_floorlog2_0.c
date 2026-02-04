#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

extern OPJ_INT32 a;
extern OPJ_INT32 l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    OPJ_INT32 *access_ptr;
    OPJ_INT32 temp_storage[64];
    access_ptr = temp_storage;

    for (l = 0; a > 1; l++) {
        *(access_ptr + l * 2) = a; // Strided write: every other element
        a >>= 1;
    }
}
