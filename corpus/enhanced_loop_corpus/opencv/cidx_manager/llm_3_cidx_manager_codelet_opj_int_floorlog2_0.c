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
    OPJ_INT32 index = 0;
    for (l = 0; a > 1; l++) {
        arr[index] = a;  // Consecutive array access
        index++;
        a >>= 1;
    }
}
