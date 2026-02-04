#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float OPJ_FLOAT32;
typedef size_t OPJ_SIZE_T;
typedef uint32_t OPJ_UINT32;
typedef int32_t OPJ_INT32;

OPJ_FLOAT32 *lMct;
OPJ_SIZE_T i;
OPJ_UINT32 lNbMatCoeff;
OPJ_INT32 *lCurrentMatrix;
OPJ_UINT32 lMultiplicator;

void init_vars() {
    lMultiplicator = 1000;
    lNbMatCoeff = 1048576; // ~4MB of data for lCurrentMatrix and similar for lMct

    lMct = (OPJ_FLOAT32*)calloc(lNbMatCoeff, sizeof(OPJ_FLOAT32));
    if (!lMct) exit(1);
    for (OPJ_SIZE_T idx = 0; idx < lNbMatCoeff; ++idx) {
        lMct[idx] = (OPJ_FLOAT32)(idx % 256) + 0.5f;
    }

    lCurrentMatrix = (OPJ_INT32*)calloc(lNbMatCoeff, sizeof(OPJ_INT32));
    if (!lCurrentMatrix) exit(1);
}