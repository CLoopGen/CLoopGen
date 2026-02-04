#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

extern OPJ_INT32 a;
extern OPJ_INT32 l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    OPJ_INT32 arr[32];
    OPJ_INT32 index = 0;
    for (l = 0; a > 1; l++) {
        arr[index] = a;  // Store current value in consecutive memory locations
        a >>= 1;
        index++;
    }
    // Dummy use of arr to prevent optimization away
    if (index > 0) a = arr[0];
}
