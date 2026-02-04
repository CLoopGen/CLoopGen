#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *dst;
extern int *src0;
extern int len;
extern int i;
extern int *src1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len; i += 2) {
        float r0, r1;
        // Remove potential RAW by precomputing scaling factor
        const float scale = 1.F / (2.F * 2147483647);
        if (i < len) {
            r0 = src0[i] * scale + src1[i] * scale;
            dst[i] = r0;
        }
        if (i + 1 < len) {
            r1 = src0[i+1] * scale + src1[i+1] * scale;
            dst[i+1] = r1;
        }
        // Eliminate loop-carried dependencies entirely; fully unrolled by 2 with no cross-iteration dependence
    }
}
