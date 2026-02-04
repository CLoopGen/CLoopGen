#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char OPJ_BYTE;

typedef size_t OPJ_SIZE_T;

typedef uint32_t OPJ_UINT32;

typedef float OPJ_FLOAT32;

extern OPJ_BYTE *pDecodingData;
extern OPJ_SIZE_T n;
extern OPJ_UINT32 pNbComp;
extern OPJ_FLOAT32 *lMct;
extern OPJ_SIZE_T i;
extern OPJ_UINT32 j;
extern OPJ_UINT32 k;
extern OPJ_FLOAT32 *lCurrentData;
extern OPJ_FLOAT32 *lCurrentResult;
extern OPJ_FLOAT32 **lData;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n; ++i) {
        lMct = (OPJ_FLOAT32 *)pDecodingData;
        for (j = 0; j < pNbComp; ++j) {
            lCurrentData[j] = (OPJ_FLOAT32)(*(lData[j]));
            lCurrentResult[j] = 0;
            for (k = 0; k < pNbComp; ++k) {
                lCurrentResult[j] += *(lMct++) * lCurrentData[k];
            }
            *(lData[j]++) = (OPJ_FLOAT32)(lCurrentResult[j]);
        }
    }
}
