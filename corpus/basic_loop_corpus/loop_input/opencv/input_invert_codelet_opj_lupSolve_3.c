#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef float OPJ_FLOAT32;
typedef uint32_t OPJ_UINT32;

OPJ_FLOAT32 *pVector;
OPJ_UINT32 nb_compo;
OPJ_FLOAT32 *p_intermediate_data;
OPJ_UINT32 i;
OPJ_UINT32 j;
OPJ_FLOAT32 sum;
OPJ_FLOAT32 *lCurrentPtr;
OPJ_FLOAT32 *lIntermediatePtr;
OPJ_FLOAT32 *lTmpMatrix;
OPJ_FLOAT32 *lLineMatrix;
OPJ_UINT32 *lCurrentPermutationPtr;

void init_vars() {
    nb_compo = 4096;

    pVector = (OPJ_FLOAT32*)aligned_alloc(32, nb_compo * sizeof(OPJ_FLOAT32));
    p_intermediate_data = (OPJ_FLOAT32*)aligned_alloc(32, nb_compo * sizeof(OPJ_FLOAT32));
    lLineMatrix = (OPJ_FLOAT32*)aligned_alloc(32, nb_compo * nb_compo * sizeof(OPJ_FLOAT32));
    lIntermediatePtr = (OPJ_FLOAT32*)aligned_alloc(32, nb_compo * sizeof(OPJ_FLOAT32));
    lCurrentPermutationPtr = (OPJ_UINT32*)aligned_alloc(32, nb_compo * sizeof(OPJ_UINT32));

    for (OPJ_UINT32 idx = 0; idx < nb_compo; ++idx) {
        pVector[idx] = (OPJ_FLOAT32)(idx + 1) * 0.5f;
        p_intermediate_data[idx] = (OPJ_FLOAT32)(idx) * 0.1f;
        lIntermediatePtr[idx] = 0.0f;
        lCurrentPermutationPtr[idx] = idx % nb_compo;
    }

    for (OPJ_UINT32 row = 0; row < nb_compo; ++row) {
        for (OPJ_UINT32 col = 0; col <= row; ++col) {
            lLineMatrix[row * nb_compo + col] = (OPJ_FLOAT32)(row + col + 1) * 0.01f;
        }
        for (OPJ_UINT32 col = row + 1; col < nb_compo; ++col) {
            lLineMatrix[row * nb_compo + col] = 0.0f;
        }
    }

    i = 0;
    j = 0;
    sum = 0.0f;
    lCurrentPtr = NULL;
    lTmpMatrix = NULL;
}