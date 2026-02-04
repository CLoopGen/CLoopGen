#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

extern OPJ_INT32 a;
extern OPJ_INT32 l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    OPJ_INT32 *ptr = &a;
    OPJ_INT32 temp_arr[8];
    for (l = 0; l < 8 && a > 1; l++) {
        temp_arr[l] = *(ptr);  // Consecutive write to temporary array
        a >>= 1;
    }
    // Ensure side effect on 'a' is preserved through indirect use
    if (l > 0) {
        a = temp_arr[l-1];
    }
}
