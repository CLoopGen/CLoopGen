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
for (k = (OPJ_INT32)nb_compo - 1; k >= 0; k -= 2) {
    OPJ_FLOAT32 sum1 = 0.0, sum2 = 0.0;
    OPJ_FLOAT32 u1, u2;
    OPJ_FLOAT32 *lTmpMatrix1 = lLineMatrix;
    OPJ_FLOAT32 *lTmpMatrix2 = lLineMatrix - lStride;
    OPJ_FLOAT32 *lCurrentPtr1 = lDestPtr--;
    OPJ_FLOAT32 *lCurrentPtr2 = lDestPtr--;
    u1 = *(lTmpMatrix1++);
    u2 = *(lTmpMatrix2++);
    for (j = (OPJ_UINT32)(k + 1); j < nb_compo; ++j) {
        sum1 += (*(lTmpMatrix1++)) * (*(lCurrentPtr1++));
        sum2 += (*(lTmpMatrix2++)) * (*(lCurrentPtr2++));
    }
    OPJ_FLOAT32 val1 = (*(lGeneratedData--) - sum1) / u1;
    OPJ_FLOAT32 val2 = (*(lGeneratedData--) - sum2) / u2;
    *(lBeginPtr--) = val1;
    *(lBeginPtr--) = val2;
    lLineMatrix -= (lStride * 2);
}
if (k == -1) {
    k = 0;
    sum = 0.0;
    lTmpMatrix = lLineMatrix;
    u = *(lTmpMatrix++);
    lCurrentPtr = lDestPtr;
    for (j = (OPJ_UINT32)(k + 1); j < nb_compo; ++j) {
        sum += (*(lTmpMatrix++)) * (*(lCurrentPtr++));
    }
    *(lBeginPtr--) = (*(lGeneratedData--) - sum) / u;
}
}
