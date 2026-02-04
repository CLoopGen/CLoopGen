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
    OPJ_UINT32 local_i = i;
    OPJ_FLOAT32 *local_fw = fw;
    for (; local_i < iters_common; local_i++) {
        if (local_i % 2 == 0) {
            local_fw[0] *= c1;
        } else {
            local_fw[1] *= c2;
        }
        local_fw += 2;
    }
    i = local_i;
    fw = local_fw;
}
