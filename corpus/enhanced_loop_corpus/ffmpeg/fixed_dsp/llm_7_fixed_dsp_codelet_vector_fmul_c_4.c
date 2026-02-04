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
    int64_t prev_accu = 0;
    for (i = 0; i < len; i++) {
        accu = (int64_t)src0[i] * src1[i] + prev_accu; // Introduce loop-carried RAW and WAW dependency via `prev_accu`
        dst[i] = (int)((accu + 1073741824) >> 31);
        prev_accu = accu; // Create loop-carried dependency (value used in next iteration)
    }
}
