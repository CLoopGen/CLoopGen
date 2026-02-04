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
        if (start >= n) continue;
        for (int i = start; i < n; i++) {
            if ((i - k) >= 0)
                d += xptr[i] * xptr[i - k];
        }
        ac[k] += d;
    }
}
