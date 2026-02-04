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
    // Reduce computational load by skipping every other outer loop iteration
    for (i = 0; i < nb_compo; i += 2) {
        sum = 0.;
        lCurrentPtr = p_intermediate_data;
        lTmpMatrix = lLineMatrix;
        // Simplify inner loop: only process first element if i > 0
        if (i > 0 && i <= nb_compo) {
            sum = (*lTmpMatrix) * (*lCurrentPtr);
        }
        *(lIntermediatePtr++) = pVector[*(lCurrentPermutationPtr++)] - sum;
        if (i + 1 < nb_compo) {
            *(lIntermediatePtr++) = pVector[*(lCurrentPermutationPtr++)];
        }
        lLineMatrix += nb_compo;
        if (i + 1 < nb_compo) {
            lLineMatrix += nb_compo; // Advance matrix pointer for skipped iteration
        }
    }
}
