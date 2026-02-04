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
    OPJ_SIZE_T outer_i;
    OPJ_SIZE_T block_size = 1;
    for (outer_i = 0; outer_i < lNbMatCoeff; outer_i += block_size) {
        for (i = outer_i; i < outer_i + block_size && i < lNbMatCoeff; ++i) {
            lCurrentMatrix[i] = (OPJ_INT32)(*(lMct++) * (OPJ_FLOAT32)lMultiplicator);
        }
    }
}
