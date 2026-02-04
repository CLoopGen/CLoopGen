#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst1;
extern int16_t *dst2;
extern int dstWidth;
extern  uint8_t *src1;
extern  uint8_t *src2;
extern int srcW;
extern int xInc;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access — simulate striding by skipping every other element in source (though clamped to last valid index)
    // This introduces a non-unit stride perception even if index is clamped, mimicking future extensibility to true striding
    int fixed_src_idx = srcW - 1;
    int stride = 1; // Logical stride placeholder (could be parameterized in extended versions)
    for (i = dstWidth - 1; (i * xInc) >> 16 >= srcW - 1; i -= stride) {
        int8_t adjusted_i = i; // Ensure within bounds after stride
        if (adjusted_i >= 0) {
            dst1[adjusted_i] = src1[fixed_src_idx] * 128;
            dst2[adjusted_i] = src2[fixed_src_idx] * 128;
        }
    }
}
