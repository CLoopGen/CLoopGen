#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

extern OPJ_INT32 *restrict row;
extern OPJ_INT32 *restrict tmp;
extern  OPJ_INT32 sn;
extern OPJ_INT32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with array offset pre-computation
    OPJ_INT32 *restrict r = row + 1;  // Shift base pointer to simplify indexing
    for (i = 1; i < sn; i++) {
        OPJ_INT32 idx = i << 1;  // Pre-compute 2*i
        tmp[sn + i] = r[idx] - ((r[idx + 1] + r[idx - 1]) >> 1);
    }
}
