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
        OPJ_INT32 sum_uv = temp_c1 + temp_c2;
        OPJ_INT32 g = temp_c0 - (sum_uv >> 2);
        OPJ_INT32 r = temp_c2 + g;
        OPJ_INT32 b = temp_c1 + g;
        // Eliminate potential WAW and WAR hazards by reordering independent computations
        c2[i] = b; // Write b first
        c1[i] = g; // Then g
        c0[i] = r; // Final write to c0[i], removing artificial write-after-write with earlier steps
    }
}
