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
    if (n > 0) {
        dst[0] += (UINTFLOAT)((src[0][0]) * (src[0][0]) + (src[0][1]) * (src[0][1]));
        for (i = 1; i < n; i++) {
            dst[i] += (UINTFLOAT)((src[i][0]) * (src[i][0]) + (src[i][1]) * (src[i][1])) + dst[i-1];
        }
    }
}
