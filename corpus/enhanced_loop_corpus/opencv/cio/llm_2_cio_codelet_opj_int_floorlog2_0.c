#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

extern OPJ_INT32 a;
extern OPJ_INT32 l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    OPJ_INT32 arr[1000];
    for (l = 0; a > 1 && l < 1000; l++) {
        arr[l] = a;
        a >>= 1;
    }
    // Consecutive memory write pattern introduced via local array
}
