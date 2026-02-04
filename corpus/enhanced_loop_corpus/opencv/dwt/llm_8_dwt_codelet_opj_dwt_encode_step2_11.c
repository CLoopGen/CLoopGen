#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float OPJ_FLOAT32;

typedef uint32_t OPJ_UINT32;

extern OPJ_FLOAT32 *fw;
extern OPJ_FLOAT32 c;
extern OPJ_UINT32 i;
extern OPJ_UINT32 imax;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    OPJ_UINT32 j;
    for (; i < imax; ++i) {
        fw[-1] += (fw[-2] + fw[0]) * c;
        fw[-1] += (fw[0] + fw[2]) * c;  // Increased arithmetic operations
        fw[-1] += (fw[-4] + fw[-2]) * c;
        fw += 2;
        // Unroll effect: process more computations per iteration
    }
}
