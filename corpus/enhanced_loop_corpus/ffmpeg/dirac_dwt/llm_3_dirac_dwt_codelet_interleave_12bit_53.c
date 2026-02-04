#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *dst;
extern int32_t *src0;
extern int32_t *src1;
extern int w2;
extern int add;
extern int shift;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access with Interleaved Input Reading
    // Access src0 and src1 with a stride of 2, processing elements in an interleaved fashion.
    // This simulates a scenario where input data might be packed or comes from a strided buffer.
    // We assume w2 is even for safe access (or handled externally).
    for (i = 0; i < w2; i += 2) {
        if (i + 1 < w2) {
            // Process two elements at once with strided writes
            dst[4 * i / 2 + 0] = ((int)(src0[i] + (unsigned int)add)) >> shift;
            dst[4 * i / 2 + 1] = ((int)(src1[i] + (unsigned int)add)) >> shift;
            dst[4 * i / 2 + 2] = ((int)(src0[i + 1] + (unsigned int)add)) >> shift;
            dst[4 * i / 2 + 3] = ((int)(src1[i + 1] + (unsigned int)add)) >> shift;
        } else {
            // Handle odd-sized w2 safely
            dst[2 * i] = ((int)(src0[i] + (unsigned int)add)) >> shift;
            dst[2 * i + 1] = ((int)(src1[i] + (unsigned int)add)) >> shift;
        }
    }
    // Final cleanup loop for any remaining element if w2 is odd
    if (w2 % 2 == 1) {
        i = w2 - 1;
        dst[2 * i] = ((int)(src0[i] + (unsigned int)add)) >> shift;
        dst[2 * i + 1] = ((int)(src1[i] + (unsigned int)add)) >> shift;
    }
}
