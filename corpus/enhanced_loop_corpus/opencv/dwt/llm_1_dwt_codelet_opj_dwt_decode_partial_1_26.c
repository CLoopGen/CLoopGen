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
    OPJ_INT32 temp_i = i;
    for (; temp_i < i_max; temp_i++) {
        for (OPJ_INT32 inner = 0; inner < 1; inner++) {
            a[(1 + (temp_i) * 2)] += (a[(temp_i) * 2] + a[(temp_i + 1) * 2]) >> 1;
        }
    }
}
