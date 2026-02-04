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
for (k = (OPJ_INT32)nb_compo - 1; k != -1; --k) {
    sum = 0.0;
    lTmpMatrix = lLineMatrix;
    u = *(lTmpMatrix++);
    lCurrentPtr = lDestPtr--;
    for (j = (OPJ_UINT32)(k + 1); j < nb_compo; j += 2) {
        OPJ_FLOAT32 term1 = 0.0, term2 = 0.0;
        term1 = (*(lTmpMatrix++)) * (*(lCurrentPtr++));
        if (j + 1 < nb_compo) {
            term2 = (*(lTmpMatrix++)) * (*(lCurrentPtr++));
            sum += term1 + term2;
        } else {
            sum += term1;
        }
    }
    *(lBeginPtr--) = (*(lGeneratedData--) - sum) / u;
    lLineMatrix -= lStride;
}
}
