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
    int step = 2;
    int remainder = (n - (k + fastN)) % 2;
    for (int i = k + fastN; i < n - remainder; i += step) {
        d += xptr[i] * xptr[i - k];
        d += xptr[i + 1] * xptr[i + 1 - k];
    }
    // Handle leftover iteration if needed
    if (remainder && (n - 1) >= k + fastN)
        d += xptr[n - 1] * xptr[n - 1 - k];
    ac[k] += d;
}
}
