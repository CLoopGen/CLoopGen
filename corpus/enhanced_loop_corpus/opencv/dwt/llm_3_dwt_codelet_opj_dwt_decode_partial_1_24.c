#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

extern OPJ_INT32 *a;
extern OPJ_INT32 i;
extern OPJ_INT32 i_max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    OPJ_INT32 *ptr_a = a;
    for (; i < i_max; i++) {
        OPJ_INT32 val1 = *(ptr_a + 2*(i-1) + 1);
        OPJ_INT32 val2 = *(ptr_a + 2*i + 1);
        *(ptr_a + 2*i) -= (val1 + val2 + 2) >> 2;
    }
}
