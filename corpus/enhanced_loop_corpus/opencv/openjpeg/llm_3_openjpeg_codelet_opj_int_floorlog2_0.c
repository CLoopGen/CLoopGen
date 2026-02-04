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
        temp_arr[l] = *ptr;    // Consecutive write to temporary array
        *ptr >>= 1;            // Update original value via pointer
    }
    if (l == 8) l--;           // Ensure l reflects correct iteration count if bounded
}
