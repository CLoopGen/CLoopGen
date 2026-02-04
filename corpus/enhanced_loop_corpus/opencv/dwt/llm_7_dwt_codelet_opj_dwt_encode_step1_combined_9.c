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
    OPJ_FLOAT32 local_c1 = c1;
    OPJ_FLOAT32 local_c2 = c2;
    OPJ_FLOAT32 *local_fw = fw;
    for (; i < iters_common; i++) {
        local_fw[0] = local_fw[0] * local_c1;
        local_fw[1] = local_fw[1] * local_c2;
        local_fw += 2;
    }
    fw = local_fw; // Update global fw after loop
}
