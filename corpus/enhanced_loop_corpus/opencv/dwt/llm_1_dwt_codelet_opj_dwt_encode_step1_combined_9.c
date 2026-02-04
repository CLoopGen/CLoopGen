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
    for (OPJ_UINT32 outer = 0; outer < iters_common / 2; outer++) {
        for (OPJ_UINT32 inner = 0; inner < 2 && i < iters_common; inner++) {
            fw[0] *= c1;
            fw[1] *= c2;
            fw += 2;
            i++;
        }
    }
}
