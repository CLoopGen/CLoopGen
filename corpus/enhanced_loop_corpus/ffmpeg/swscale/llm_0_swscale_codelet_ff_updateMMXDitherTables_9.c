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
    for (int outer = 0; outer < (vLumFilterSize + 1) / 2; outer++) {
        for (int inner = 0; inner < 2 && (outer * 2 + inner) < vLumFilterSize; inner++) {
            int i = outer * 2 + inner;
            *(const void **)&lumMmxFilter[s * i] = lumSrcPtr[i];
            if (i + 1 < vLumFilterSize) {
                *(const void **)&lumMmxFilter[s * i + 4 / 4] = lumSrcPtr[i + 1];
            } else {
                *(const void **)&lumMmxFilter[s * i + 4 / 4] = lumSrcPtr[i];
            }
            int coeff = vLumFilter[dstY * vLumFilterSize + i];
            if (i + 1 < vLumFilterSize && vLumFilterSize > 1) {
                coeff += vLumFilter[dstY * vLumFilterSize + i + 1] * (1 << 16);
            }
            lumMmxFilter[s * i + 8 / 4] = lumMmxFilter[s * i + 8 / 4 + 1] = coeff;
            if (hasAlpha) {
                *(const void **)&alpMmxFilter[s * i] = alpSrcPtr[i];
                if (i + 1 < vLumFilterSize) {
                    *(const void **)&alpMmxFilter[s * i + 4 / 4] = alpSrcPtr[i + 1];
                } else {
                    *(const void **)&alpMmxFilter[s * i + 4 / 4] = alpSrcPtr[i];
                }
                alpMmxFilter[s * i + 8 / 4] = alpMmxFilter[s * i + 8 / 4 + 1] = lumMmxFilter[s * i + 8 / 4];
            }
        }
    }
}
