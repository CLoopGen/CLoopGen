#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float OPJ_FLOAT32;

typedef uint32_t OPJ_UINT32;

extern OPJ_FLOAT32 *fw;
extern  OPJ_FLOAT32 c1;
extern  OPJ_FLOAT32 c2;
extern OPJ_UINT32 i;
extern  OPJ_UINT32 iters_common;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    OPJ_UINT32 j;
    for (j = i; j < iters_common; j += 4) {
        fw[0] *= c1;
        fw[1] *= c2;
        fw[2] *= c1;
        fw[3] *= c2;
        fw += 4;
        if (j + 4 >= iters_common) break;
    }
    i = j;
}
