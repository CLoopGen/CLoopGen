#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int INTFLOAT;

extern INTFLOAT (*dst)[2];
extern INTFLOAT (*src0)[2];
extern INTFLOAT *src1;
extern int n;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            dst[i][j] = (int)(((int64_t)(src0[i][j]) * (src1[i]) + 32768) >> 16);
        }
    }
}
