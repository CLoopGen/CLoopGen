#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float INTFLOAT;

extern INTFLOAT (*dst)[2];
extern INTFLOAT (*src0)[2];
extern INTFLOAT *src1;
extern int n;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (n > 0) {
        for (i = 0; i < n; i += 2) {
            int upper = (i + 1 < n) ? i + 2 : n;
            for (int k = i; k < upper; k++) {
                dst[k][0] = src0[k][0] * src1[k];
                dst[k][1] = src0[k][1] * src1[k];
            }
        }
    }
}
