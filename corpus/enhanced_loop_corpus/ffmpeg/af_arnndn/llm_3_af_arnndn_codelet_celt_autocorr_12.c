#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *ac;
extern int lag;
extern int n;
extern int fastN;
extern  float *xptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int k = 0; k <= lag; k++) {
    float d = 0.F;
    float *xptr_base1 = &xptr[k + fastN];
    float *xptr_base2 = &xptr[fastN];
    int length = n - (k + fastN);
    for (int i = 0; i < length; i++) {
        d += xptr_base1[i] * xptr_base2[i];
    }
    ac[k] += d;
}
}
