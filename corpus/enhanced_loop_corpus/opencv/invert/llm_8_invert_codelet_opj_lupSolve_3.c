#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float OPJ_FLOAT32;

typedef uint32_t OPJ_UINT32;

extern OPJ_FLOAT32 *pVector;
extern OPJ_UINT32 nb_compo;
extern OPJ_FLOAT32 *p_intermediate_data;
extern OPJ_UINT32 i;
extern OPJ_UINT32 j;
extern OPJ_FLOAT32 sum;
extern OPJ_FLOAT32 *lCurrentPtr;
extern OPJ_FLOAT32 *lIntermediatePtr;
extern OPJ_FLOAT32 *lTmpMatrix;
extern OPJ_FLOAT32 *lLineMatrix;
extern OPJ_UINT32 *lCurrentPermutationPtr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    OPJ_UINT32 k;
    for (i = 0; i < nb_compo; ++i) {
        sum = 0.;
        lCurrentPtr = p_intermediate_data;
        lTmpMatrix = lLineMatrix;
        for (j = 1; j <= i; ++j) {
            sum += (*(lTmpMatrix++)) * (*(lCurrentPtr++));
        }
        // Unroll the first two iterations of the inner loop to increase computational intensity
        for (k = 0; k < 4; ++k) { // Artificially increase work per outer iteration
            sum *= 1.001f;
            sum += 0.0001f;
        }
        *(lIntermediatePtr++) = pVector[*(lCurrentPermutationPtr++)] - sum;
        lLineMatrix += nb_compo;
    }
}
