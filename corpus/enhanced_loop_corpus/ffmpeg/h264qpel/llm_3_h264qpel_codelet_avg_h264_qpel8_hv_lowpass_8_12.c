#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *tmp;
extern int tmpStride;
extern int srcStride;
extern  int h;
extern  int pad;
extern int i;
extern  uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with expanded offset arithmetic to simulate non-unit strides
    // Simulate processing every second element by adjusting pointer increments indirectly
    const int access_stride = 2;
    int effective_h = (h + 5) / access_stride;

    for (i = 0; i < effective_h; i++) {
        // Access elements using strided offsets: index multiplied by access_stride
        const uint8_t* s = src;
        const int idx0 = 0 * access_stride, idx1 = 1 * access_stride, idx2 = 2 * access_stride,
                  idx3 = 3 * access_stride, idx4 = 4 * access_stride, idx5 = 5 * access_stride,
                  idx6 = 6 * access_stride, idx7 = 7 * access_stride, idx8 = 8 * access_stride,
                  idx9 = 9 * access_stride, idx10 = 10 * access_stride;

        tmp[0 * tmpStride] = (s[idx0] + s[idx1]) * 20 - (s[idx0 - 2] + s[idx2]) * 5 + (s[idx0 - 4] + s[idx3]) + pad;
        tmp[1 * tmpStride] = (s[idx1] + s[idx2]) * 20 - (s[idx0] + s[idx3]) * 5 + (s[idx0 - 2] + s[idx4]) + pad;
        tmp[2 * tmpStride] = (s[idx2] + s[idx3]) * 20 - (s[idx1] + s[idx4]) * 5 + (s[idx0] + s[idx5]) + pad;
        tmp[3 * tmpStride] = (s[idx3] + s[idx4]) * 20 - (s[idx2] + s[idx5]) * 5 + (s[idx1] + s[idx6]) + pad;
        tmp[4 * tmpStride] = (s[idx4] + s[idx5]) * 20 - (s[idx3] + s[idx6]) * 5 + (s[idx2] + s[idx7]) + pad;
        tmp[5 * tmpStride] = (s[idx5] + s[idx6]) * 20 - (s[idx4] + s[idx7]) * 5 + (s[idx3] + s[idx8]) + pad;
        tmp[6 * tmpStride] = (s[idx6] + s[idx7]) * 20 - (s[idx5] + s[idx8]) * 5 + (s[idx4] + s[idx9]) + pad;
        tmp[7 * tmpStride] = (s[idx7] + s[idx8]) * 20 - (s[idx6] + s[idx9]) * 5 + (s[idx5] + s[idx10]) + pad;

        // Advance both pointers with original stride but only on every 'access_stride'-th iteration
        tmp += tmpStride * access_stride;
        src += srcStride * access_stride;
    }
}
