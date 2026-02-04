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
    for (int i = 0; i < 8; ++i) {
        temp_arr[i] = a >> i;  // Precompute shifted values
    }
    l = 0;
    for (OPJ_INT32 stride = 2; l < 8 && a > 1; l++, stride = (stride + 2) % 8 + 1) {
        a = temp_arr[stride % 8];  // Indirect and strided access pattern
        a >>= 1;
    }
}
