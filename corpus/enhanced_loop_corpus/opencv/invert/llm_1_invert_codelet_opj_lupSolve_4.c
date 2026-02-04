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
if (nb_compo > 0) {
    for (k = (OPJ_INT32)nb_compo - 1; k != -1; --k) {
        sum = 0.;
        lTmpMatrix = lLineMatrix;
        u = *(lTmpMatrix++);
        lCurrentPtr = lDestPtr--;
        OPJ_UINT32 inner_loop_bound = nb_compo;
        for (j = (OPJ_UINT32)(k + 1); j < inner_loop_bound; ++j) {
            OPJ_FLOAT32 tmp_val = *(lTmpMatrix++);
            OPJ_FLOAT32 curr_val = *(lCurrentPtr++);
            sum += tmp_val * curr_val;
        }
        OPJ_FLOAT32 generated_val = *(lGeneratedData--);
        OPJ_FLOAT32 result = (generated_val - sum) / u;
        *(lBeginPtr--) = result;
        lLineMatrix -= lStride;
    }
}
}
