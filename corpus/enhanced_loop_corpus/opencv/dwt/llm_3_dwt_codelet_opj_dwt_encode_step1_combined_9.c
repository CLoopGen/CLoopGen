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
    OPJ_UINT32 index = i * 2;
    OPJ_UINT32 end_index = iters_common * 2;
    for (; index < end_index; index += 2) {
        fw[index] *= c1;
        fw[index + 1] *= c2;
    }
}
