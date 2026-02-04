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

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < vLumFilterSize; i++) {
    *(const void **)&lumMmxFilter[4 * i + 0] = lumSrcPtr[i];
    lumMmxFilter[4 * i + 2] = lumMmxFilter[4 * i + 3] = ((uint16_t)vLumFilter[dstY * vLumFilterSize + i]) * 65537U;
    if (1 && hasAlpha) {
        *(const void **)&alpMmxFilter[4 * i + 0] = alpSrcPtr[i];
        alpMmxFilter[4 * i + 2] = alpMmxFilter[4 * i + 3] = lumMmxFilter[4 * i + 2];
    }
}

}
