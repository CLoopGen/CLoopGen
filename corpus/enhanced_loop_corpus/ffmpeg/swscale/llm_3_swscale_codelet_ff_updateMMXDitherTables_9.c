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



void loop() {
    // Variant 2: Strided memory access using indirect indexing via offset array (simulated stride)
    int* restrict indexMap = (int*)alloca(vLumFilterSize * sizeof(int));
    for (int j = 0; j < vLumFilterSize; j++) {
        indexMap[j] = j; // Identity map, but allows future generalization to arbitrary strides
    }

    int baseOffset = dstY * vLumFilterSize;
    for (i = 0; i < vLumFilterSize; i += 2) {
        int mapped_i = indexMap[i];
        int mapped_i1 = indexMap[i + (vLumFilterSize > 1)];
        int stride = s * i;

        // Use strided access through indirect addressing
        *(const void **)&lumMmxFilter[stride] = lumSrcPtr[mapped_i];
        *(const void **)&lumMmxFilter[stride + 1] = lumSrcPtr[mapped_i1];

        int32_t filt0 = vLumFilter[baseOffset + mapped_i];
        int32_t filt1 = (vLumFilterSize > 1) ? vLumFilter[baseOffset + mapped_i1] : 0;
        int32_t packed_filter = filt0 + (filt1 << 16);
        lumMmxFilter[stride + 2] = packed_filter;
        lumMmxFilter[stride + 3] = packed_filter;

        if (hasAlpha) {
            *(const void **)&alpMmxFilter[stride] = alpSrcPtr[mapped_i];
            *(const void **)&alpMmxFilter[stride + 1] = alpSrcPtr[mapped_i1];
            alpMmxFilter[stride + 2] = packed_filter;
            alpMmxFilter[stride + 3] = packed_filter;
        }
    }
}
