#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float OPJ_FLOAT32;

typedef size_t OPJ_SIZE_T;

typedef uint32_t OPJ_UINT32;

typedef int32_t OPJ_INT32;

extern OPJ_FLOAT32 *lMct;
extern OPJ_SIZE_T i;
extern OPJ_UINT32 lNbMatCoeff;
extern OPJ_INT32 *lCurrentMatrix;
extern OPJ_UINT32 lMultiplicator;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    OPJ_SIZE_T unroll_factor = 4;
    OPJ_SIZE_T remainder = lNbMatCoeff % unroll_factor;
    OPJ_SIZE_T limit = lNbMatCoeff - remainder;

    for (i = 0; i < limit; i += unroll_factor) {
        lCurrentMatrix[i]     = (OPJ_INT32)(lMct[0] * (OPJ_FLOAT32)lMultiplicator);
        lCurrentMatrix[i + 1] = (OPJ_INT32)(lMct[1] * (OPJ_FLOAT32)lMultiplicator);
        lCurrentMatrix[i + 2] = (OPJ_INT32)(lMct[2] * (OPJ_FLOAT32)lMultiplicator);
        lCurrentMatrix[i + 3] = (OPJ_INT32)(lMct[3] * (OPJ_FLOAT32)lMultiplicator);
        lMct += unroll_factor;
    }

    for (; i < lNbMatCoeff; ++i) {
        lCurrentMatrix[i] = (OPJ_INT32)(*lMct++ * (OPJ_FLOAT32)lMultiplicator);
    }
}
