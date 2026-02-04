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
    OPJ_INT32 temp = a;
    OPJ_INT32 arr[8];
    
    // Initialize auxiliary array with derived values
    for (OPJ_INT32 i = 0; i < 8; i++) {
        arr[i] = temp + i * 4;
    }

    for (l = 0; a > 1; l++) {
        a >>= 1;
        ptr = &arr[l % 8];  // Indirect access: pointer updated to point into array
        if (*ptr <= 1) break;
    }
}
