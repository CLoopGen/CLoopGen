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
    OPJ_FLOAT32 temp_sum = 0.0;
    for (i = 0; i < nb_compo; ++i) {
        sum = 0.;
        lCurrentPtr = p_intermediate_data;
        lTmpMatrix = lLineMatrix;
        for (j = 1; j <= i; ++j) {
            sum += (*(lTmpMatrix++)) * (*(lCurrentPtr++));
        }
        temp_sum = pVector[*(lCurrentPermutationPtr)] - sum;
        *(lIntermediatePtr++) = temp_sum;
        lCurrentPermutationPtr++;
        lLineMatrix += nb_compo;
    }
}
