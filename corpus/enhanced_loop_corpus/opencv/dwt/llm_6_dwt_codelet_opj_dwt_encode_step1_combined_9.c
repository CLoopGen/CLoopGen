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
    OPJ_FLOAT32 temp1 = c1;
    OPJ_FLOAT32 temp2 = c2;
    for (; i < iters_common; i++) {
        OPJ_FLOAT32 f0 = fw[0];
        OPJ_FLOAT32 f1 = fw[1];
        f0 *= temp1;
        f1 *= temp2;
        fw[0] = f0;
        fw[1] = f1;
        fw += 2;
    }
}
