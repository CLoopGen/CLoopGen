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
        INTFLOAT a = src[i][0];
        INTFLOAT b = src[i][1];
        INTFLOAT sum_sq = a * a + b * b;
        dst[i] += (UINTFLOAT)(sum_sq * sum_sq); // Now computing (a² + b²)² instead of (a² + b²)
    }
}
