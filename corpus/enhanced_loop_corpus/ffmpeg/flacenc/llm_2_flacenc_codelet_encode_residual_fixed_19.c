#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *res;
extern  int32_t *smp;
extern int n;
extern int order;
extern int i;
extern int a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 4 instead of 2
    for (i = order; i < n; i += 4) {
        int b = smp[i] - smp[i - 1];
        res[i] = b - a;
        a = smp[i + 1] - smp[i];
        res[i + 1] = a - b;

        // Unroll second iteration manually within the same stride
        if (i + 2 < n) {
            int b2 = smp[i + 2] - smp[i + 1];
            res[i + 2] = b2 - a;
            a = smp[i + 3] - smp[i + 2];
            res[i + 3] = a - b2;
        }
    }
}
