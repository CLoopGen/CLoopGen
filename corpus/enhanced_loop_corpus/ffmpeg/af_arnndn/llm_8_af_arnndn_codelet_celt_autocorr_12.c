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
for (int k = 0; k <= lag; k += 2) {
    float d1 = 0.F, d2 = 0.F;
    int start = k + fastN;
    int start2 = (k + 1) + fastN;
    for (int i = start; i < n; i++) {
        d1 += xptr[i] * xptr[i - k];
        if (k + 1 <= lag && start2 < n)
            d2 += xptr[i] * xptr[i - (k + 1)];
    }
    ac[k] += d1;
    if (k + 1 <= lag)
        ac[k + 1] += d2;
}
}
