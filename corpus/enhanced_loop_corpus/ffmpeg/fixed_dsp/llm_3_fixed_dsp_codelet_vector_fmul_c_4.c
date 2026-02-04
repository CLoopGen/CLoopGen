#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *dst;
extern  int *src0;
extern  int *src1;
extern int len;
extern int i;
extern int64_t accu;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map (simulated with reverse order)
    for (i = 0; i < len; i++) {
        int idx = len - 1 - i;  // Reverse traversal index
        accu = (int64_t)src0[idx] * src1[idx];
        dst[idx] = (int)((accu + 1073741824) >> 31);
    }
}
