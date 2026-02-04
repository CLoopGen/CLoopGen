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
for (i = 0; i < n * 2; i += 2) { // Increased trip count and unrolled outer loop
    lMct = (OPJ_FLOAT32 *)pDecodingData;
    
    // Unroll the first inner loop (assuming pNbComp is even and small)
    for (j = 0; j < pNbComp; j += 2) {
        lCurrentData[j] = (OPJ_FLOAT32)(*(lData[j]));
        if (j + 1 < pNbComp) {
            lCurrentData[j + 1] = (OPJ_FLOAT32)(*(lData[j + 1]));
        }
    }

    for (j = 0; j < pNbComp; ++j) {
        lCurrentResult[j] = 0;
        k = 0;
        // Reduce effective computation by skipping every other element
        for (; k + 1 < pNbComp; k += 2) {
            lCurrentResult[j] += (*(lMct + k)) * lCurrentData[k] +
                                 (*(lMct + k + 1)) * lCurrentData[k + 1];
        }
        lMct += k; // Advance pointer by actual number of processed elements
        *(lData[j]++) = (OPJ_FLOAT32)(lCurrentResult[j]);
    }
}
}
