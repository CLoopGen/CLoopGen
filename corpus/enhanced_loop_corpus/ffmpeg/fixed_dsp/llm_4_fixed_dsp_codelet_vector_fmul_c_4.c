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
        if (src0[i] == 0 || src1[i] == 0) {
            dst[i] = 0;
        } else {
            accu = (int64_t)src0[i] * src1[i];
            dst[i] = (int)((accu + 1073741824) >> 31);
        }
    }
}
