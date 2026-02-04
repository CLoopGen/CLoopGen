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
    // Variant 2: Strided Memory Access with Reverse Iteration
    // Access arrays in reverse order with a negative stride to change memory access pattern
    // This can be useful for pipelines that benefit from backward traversal or cache reuse.
    for (i = w2 - 1; i >= 0; i--) {
        dst[2 * i] = ((int)(src0[i] + (unsigned int)add)) >> shift;
        dst[2 * i + 1] = ((int)(src1[i] + (unsigned int)add)) >> shift;
    }
}
