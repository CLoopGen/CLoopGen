#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

typedef uint32_t OPJ_UINT32;

extern OPJ_INT32 *restrict tmp;
extern OPJ_UINT32 c;
extern OPJ_UINT32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    OPJ_INT32 base_index = (1 + (i - 1) * 2) * 8;
    OPJ_INT32 dest_index = i * 2 * 8;
    OPJ_INT32 sum_val;
    for (c = 0; c < 8; c++) {
        sum_val = (tmp[base_index + c] + tmp[base_index + c] + 2) >> 2;
        tmp[dest_index + c] += sum_val;
        // Introduce WAW and RAW dependency by reusing sum_val in next iteration artificially
        sum_val = tmp[dest_index + c];
    }
}
