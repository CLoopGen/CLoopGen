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
    OPJ_SIZE_T step = 2;
    for (i = 0; i < lNbMatCoeff; i += step) {
        OPJ_FLOAT32 val1 = lMct[0] * (OPJ_FLOAT32)lMultiplicator;
        lCurrentMatrix[i] = (OPJ_INT32)val1;
        if (i + 1 < lNbMatCoeff) {
            OPJ_FLOAT32 val2 = lMct[1] * (OPJ_FLOAT32)lMultiplicator;
            lCurrentMatrix[i + 1] = (OPJ_INT32)val2;
        }
        lMct += step;
    }
}
