#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float INTFLOAT;

typedef float UINTFLOAT;

extern INTFLOAT *dst;
extern  INTFLOAT (*src)[2];
extern int n;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n; i++) {
        UINTFLOAT val1 = src[i][0];
        UINTFLOAT val2 = src[i][1];
        UINTFLOAT sum_sq = val1 * val1 + val2 * val2;
        if (sum_sq > 0.0f) {
            dst[i] += sum_sq;
        }
    }
}
