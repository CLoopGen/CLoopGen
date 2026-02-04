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
        arr[l] = a;        // Consecutive array write
        a >>= 1;
    }
    // Ensure side effect on 'a' is preserved even if loop runs fewer than 8 iterations
    if (l == 8 && a > 1) {
        a >>= 1;
    }
}
