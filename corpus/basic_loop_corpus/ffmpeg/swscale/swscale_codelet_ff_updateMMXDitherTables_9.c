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
    *(const void **)&lumMmxFilter[s * i] = lumSrcPtr[i];
    *(const void **)&lumMmxFilter[s * i + 4 / 4] = lumSrcPtr[i + (vLumFilterSize > 1)];
    lumMmxFilter[s * i + 8 / 4] = lumMmxFilter[s * i + 8 / 4 + 1] = vLumFilter[dstY * vLumFilterSize + i] + (vLumFilterSize > 1 ? vLumFilter[dstY * vLumFilterSize + i + 1] * (1 << 16) : 0);
    if (1 && hasAlpha) {
        *(const void **)&alpMmxFilter[s * i] = alpSrcPtr[i];
        *(const void **)&alpMmxFilter[s * i + 4 / 4] = alpSrcPtr[i + (vLumFilterSize > 1)];
        alpMmxFilter[s * i + 8 / 4] = alpMmxFilter[s * i + 8 / 4 + 1] = lumMmxFilter[s * i + 8 / 4];
    }
}

}
