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
    int start1 = k + fastN;
    int start2 = (k + 1) + fastN;
    for (int i = 0; i < n - start1; i++) {
        d1 += xptr[start1 + i] * xptr[start1 + i - k];
        if (k + 1 <= lag && start2 + i < n)
            d2 += xptr[start2 + i] * xptr[start2 + i - (k + 1)];
    }
    ac[k] += d1;
    if (k + 1 <= lag)
        ac[k + 1] += d2;
}
}
