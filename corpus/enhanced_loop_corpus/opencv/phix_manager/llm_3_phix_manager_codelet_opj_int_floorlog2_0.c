#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

extern OPJ_INT32 a;
extern OPJ_INT32 l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    OPJ_INT32 arr[8];
    for (l = 0; l < 8 && a > 1; l++) {
        arr[l] = a;       // Consecutive write access to array
        a >>= 1;
    }
    // Use the last valid value of 'l' to ensure consistent side effects
    if (l == 8) a = arr[7] >> 1;
}
