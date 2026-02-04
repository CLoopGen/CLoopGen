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
    for (i = 0; i < lNbMatCoeff && lMct != NULL; ++i) {
        OPJ_FLOAT32 temp = *(lMct++);
        if (temp > 0.0f) {
            lCurrentMatrix[i] = (OPJ_INT32)(temp * (OPJ_FLOAT32)lMultiplicator);
        } else {
            lCurrentMatrix[i] = 0;
        }
    }
}
