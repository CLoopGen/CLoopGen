#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char OPJ_BYTE;
typedef size_t OPJ_SIZE_T;
typedef uint32_t OPJ_UINT32;
typedef float OPJ_FLOAT32;

OPJ_BYTE *pDecodingData;
OPJ_SIZE_T n;
OPJ_UINT32 pNbComp;
OPJ_FLOAT32 *lMct;
OPJ_SIZE_T i;
OPJ_UINT32 j;
OPJ_UINT32 k;
OPJ_FLOAT32 *lCurrentData;
OPJ_FLOAT32 *lCurrentResult;
OPJ_FLOAT32 **lData;

void init_vars() {
    pNbComp = 4;
    n = 1000000 / (pNbComp * sizeof(OPJ_FLOAT32)) + 1;
    
    size_t total_data_size = n * pNbComp * sizeof(OPJ_FLOAT32);
    pDecodingData = (OPJ_BYTE*)calloc(total_data_size, 1);
    if (!pDecodingData) exit(1);
    
    lCurrentData = (OPJ_FLOAT32*)calloc(pNbComp, sizeof(OPJ_FLOAT32));
    lCurrentResult = (OPJ_FLOAT32*)calloc(pNbComp, sizeof(OPJ_FLOAT32));
    lData = (OPJ_FLOAT32**)calloc(pNbComp, sizeof(OPJ_FLOAT32*));
    if (!lCurrentData || !lCurrentResult || !lData) exit(1);
    
    for (OPJ_UINT32 idx = 0; idx < pNbComp; ++idx) {
        lData[idx] = (OPJ_FLOAT32*)calloc(n, sizeof(OPJ_FLOAT32));
        if (!lData[idx]) exit(1);
        for (OPJ_SIZE_T pos = 0; pos < n; ++pos) {
            lData[idx][pos] = (OPJ_FLOAT32)(pos + idx);
        }
    }
    
    lMct = (OPJ_FLOAT32*)pDecodingData;
    for (size_t mct_idx = 0; mct_idx < pNbComp * pNbComp; ++mct_idx) {
        ((OPJ_FLOAT32*)pDecodingData)[mct_idx] = 1.0f / pNbComp;
    }
}