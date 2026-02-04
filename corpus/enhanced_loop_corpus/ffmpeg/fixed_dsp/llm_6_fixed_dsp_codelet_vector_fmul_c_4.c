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
    int64_t temp_accu;
    for (i = 0; i < len; i++) {
        temp_accu = (int64_t)src0[i] * src1[i];
        accu = temp_accu; // Introduce WAW dependency on `accu` (overwritten but not carried)
        dst[i] = (int)((temp_accu + 1073741824) >> 31);
    }
}
