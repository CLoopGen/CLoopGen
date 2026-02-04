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
    OPJ_UINT32 *indices = (OPJ_UINT32*)alloca(lNbMatCoeff * sizeof(OPJ_UINT32));
    for (i = 0; i < lNbMatCoeff; ++i) {
        indices[i] = lNbMatCoeff - 1 - i; // reverse access pattern
    }
    for (i = 0; i < lNbMatCoeff; ++i) {
        OPJ_UINT32 idx = indices[i];
        lCurrentMatrix[idx] = (OPJ_INT32)(lMct[idx] * (OPJ_FLOAT32)lMultiplicator);
    }
}
