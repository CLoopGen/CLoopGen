#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef uint32_t OPJ_UINT32;

typedef int32_t OPJ_INT32;

typedef float OPJ_FLOAT32;

extern OPJ_UINT32 nb_compo;
extern OPJ_INT32 k;
extern OPJ_UINT32 j;
extern OPJ_FLOAT32 sum;
extern OPJ_FLOAT32 u;
extern OPJ_UINT32 lStride;
extern OPJ_FLOAT32 *lCurrentPtr;
extern OPJ_FLOAT32 *lDestPtr;
extern OPJ_FLOAT32 *lTmpMatrix;
extern OPJ_FLOAT32 *lLineMatrix;
extern OPJ_FLOAT32 *lBeginPtr;
extern OPJ_FLOAT32 *lGeneratedData;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
OPJ_FLOAT32 local_sum[1]; // Introduce local storage to isolate WAW and WAR dependencies
local_sum[0] = 0.0;
for (k = (OPJ_INT32)nb_compo - 1; k != -1; --k) {
    lTmpMatrix = lLineMatrix;
    u = *(lTmpMatrix++);
    lCurrentPtr = lDestPtr--;
    *local_sum = 0.0; // Reset through memory store instead of direct assignment to enforce memory dependency
    for (j = (OPJ_UINT32)(k + 1); j < nb_compo; ++j) {
        OPJ_FLOAT32 coeff = *lTmpMatrix;
        OPJ_FLOAT32 val = *lCurrentPtr;
        *lTmpMatrix++ += 0.0; // Artificially introduce a WAW on lTmpMatrix elements (no-op but creates dependency)
        *lCurrentPtr++ += 0.0; // Same for lCurrentPtr
        *local_sum = *local_sum + coeff * val; // Accumulate via memory load/store to serialize reduction
    }
    OPJ_FLOAT32 gen_val = *lGeneratedData;
    *lGeneratedData-- = gen_val; // WAR: Write after using the value, to create artificial loop-carried dependency
    *(lBeginPtr--) = (gen_val - *local_sum) / u;
    lLineMatrix -= lStride;
}
}
