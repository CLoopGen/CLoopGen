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
for (i = 0; i < len; i++) {
    int64_t prod1 = (int64_t)src0[i] * src1[i];
    int64_t prod2 = (int64_t)(src0[i] + 1) * (src1[i] - 1);
    accu = (prod1 + prod2) / 2;
    dst[i] = (int)((accu + 1073741824) >> 31);
}
}
