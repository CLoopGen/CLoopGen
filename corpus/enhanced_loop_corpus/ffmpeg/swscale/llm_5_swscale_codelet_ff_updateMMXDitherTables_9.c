#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int hasAlpha;
extern int16_t *vLumFilter;
extern int32_t *lumMmxFilter;
extern __attribute__((unused)) int32_t *alpMmxFilter;
extern  int vLumFilterSize;
extern int dstY;
extern  int16_t **lumSrcPtr;
extern  int16_t **alpSrcPtr;
extern int i;
extern int s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < vLumFilterSize; i += 2) {
    int hasDualSamples = (vLumFilterSize > 1) && (i + 1 < vLumFilterSize);
    *(const void **)&lumMmxFilter[s * i] = lumSrcPtr[i];
    *(const void **)&lumMmxFilter[s * i + 1] = hasDualSamples ? lumSrcPtr[i + 1] : lumSrcPtr[i];
    
    int32_t lowCoeff = vLumFilter[dstY * vLumFilterSize + i];
    int32_t highCoeff = hasDualSamples ? vLumFilter[dstY * vLumFilterSize + i + 1] : 0;
    lumMmxFilter[s * i + 2] = lumMmxFilter[s * i + 3] = lowCoeff + (highCoeff << 16);

    if (hasAlpha) {
        *(const void **)&alpMmxFilter[s * i] = alpSrcPtr[i];
        *(const void **)&alpMmxFilter[s * i + 1] = hasDualSamples ? alpSrcPtr[i + 1] : alpSrcPtr[i];
        alpMmxFilter[s * i + 2] = alpMmxFilter[s * i + 3] = lumMmxFilter[s * i + 2];
    }
}
}
