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
        int start = k + fastN;
        #pragma unroll
        for (int i = start; i < n; i += 2) {
            float prod1 = xptr[i] * xptr[i - k];
            float prod2 = (i + 1 < n) ? xptr[i + 1] * xptr[i + 1 - k] : 0.F;
            d += prod1 + prod2;
        }
        ac[k] = ac[k] + d;
    }
}
