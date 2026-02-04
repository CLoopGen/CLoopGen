#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

extern OPJ_INT32 a;
extern OPJ_INT32 l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    OPJ_INT32 arr[100];
    OPJ_INT32 indices[] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50}; // Predefined index pattern
    for (l = 0; a > 1 && l < 10; l++) {
        arr[indices[l]] = a;  // Indirect access via index array
        a >>= 1;
    }
}
