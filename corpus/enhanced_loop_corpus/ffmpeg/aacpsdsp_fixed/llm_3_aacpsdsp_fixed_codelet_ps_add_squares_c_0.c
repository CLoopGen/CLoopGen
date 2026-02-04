#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int INTFLOAT;

typedef unsigned int UINTFLOAT;

extern INTFLOAT *dst;
extern  INTFLOAT (*src)[2];
extern int n;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse Consecutive Memory Access (process array from end to start)
    for (i = n - 1; i >= 0; i--) {
        dst[i] += (UINTFLOAT)(int)((((int64_t)(src[i][0]) * (src[i][0])) + ((int64_t)(src[i][1]) * (src[i][1])) + 134217728) >> 28);
    }
}
