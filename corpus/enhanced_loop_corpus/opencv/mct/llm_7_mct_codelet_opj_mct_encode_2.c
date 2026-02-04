#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

typedef size_t OPJ_SIZE_T;

extern OPJ_INT32 *restrict c0;
extern OPJ_INT32 *restrict c1;
extern OPJ_INT32 *restrict c2;
extern OPJ_SIZE_T i;
extern  OPJ_SIZE_T len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; i < len; ++i) {
        OPJ_INT32 temp_c0 = c0[i];
        OPJ_INT32 temp_c1 = c1[i];
        OPJ_INT32 temp_c2 = c2[i];
        // Remove potential aliasing effects by computing all outputs before write
        OPJ_INT32 y = (temp_c0 + (temp_c1 * 2) + temp_c2) >> 2;
        OPJ_INT32 u = temp_c2 - temp_c1;
        OPJ_INT32 v = temp_c0 - temp_c1;
        // Eliminate write-after-write and write-after-read hazards via delayed write
        // All reads occur before any writes (increased independence)
        c0[i] = y;
        c1[i] = u;
        c2[i] = v;
    }
}
