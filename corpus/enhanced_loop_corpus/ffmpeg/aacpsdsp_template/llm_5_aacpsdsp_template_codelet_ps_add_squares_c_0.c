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
        UINTFLOAT temp = (UINTFLOAT)((src[i][0]) * (src[i][0]) + (src[i][1]) * (src[i][1]));
        if (i % 2 == 0) {
            dst[i] += temp;
        } else {
            dst[i] += temp * 0.5f;
        }
    }
}
