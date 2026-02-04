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
    int32_t prevLumValue = 0;
    for (i = 0; i < vLumFilterSize; i += 2) {
        int baseIdx = s * i;
        int srcOffset = dstY * vLumFilterSize + i;

        int32_t currentLum = vLumFilter[srcOffset];
        if (vLumFilterSize > 1 && i + 1 < vLumFilterSize) {
            currentLum |= (int32_t)(vLumFilter[srcOffset + 1]) << 16;
        } else {
            currentLum |= (currentLum << 16);
        }

        int32_t delayedLum = prevLumValue; 
        prevLumValue = currentLum;

        *(const void **)&lumMmxFilter[baseIdx] = lumSrcPtr[i];
        if (vLumFilterSize > 1 && i + 1 < vLumFilterSize) {
            *(const void **)&lumMmxFilter[baseIdx + 1] = lumSrcPtr[i + 1];
        } else {
            *(const void **)&lumMmxFilter[baseIdx + 1] = lumSrcPtr[i];
        }

        lumMmxFilter[baseIdx + 2] = delayedLum;
        lumMmxFilter[baseIdx + 3] = currentLum;

        if (hasAlpha) {
            *(const void **)&alpMmxFilter[baseIdx] = alpSrcPtr[i];
            if (vLumFilterSize > 1 && i + 1 < vLumFilterSize) {
                *(const void **)&alpMmxFilter[baseIdx + 1] = alpSrcPtr[i + 1];
            } else {
                *(const void **)&alpMmxFilter[baseIdx + 1] = alpSrcPtr[i];
            }
            alpMmxFilter[baseIdx + 2] = delayedLum;
            alpMmxFilter[baseIdx + 3] = currentLum;
        }
    }
}
