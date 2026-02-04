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
    OPJ_INT32 stride = 1;
    for (l = 0; a > 1; l += stride) {
        *(ptr + 0) >>= 1;  // Simulate strided memory access (stride of 1 on single var)
    }
}
