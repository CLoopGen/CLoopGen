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
    OPJ_INT32 steps[8];
    for (int i = 0; i < 8; ++i) {
        steps[i] = temp;
        temp >>= 1;
    }
    l = 0;
    for (temp = a; temp > 1; l++) {
        temp = steps[l];  // Consecutive read from precomputed array
        ptr[0] = temp >> 1;
    }
    a = ptr[0];
}
