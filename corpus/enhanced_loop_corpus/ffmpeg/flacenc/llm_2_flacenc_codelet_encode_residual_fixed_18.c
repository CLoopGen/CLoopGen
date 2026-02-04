#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *res;
extern  int32_t *smp;
extern int n;
extern int order;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = order; i < n; i += 2) {
        if (i - 2 >= 0) {
            res[i] = smp[i] - smp[i - 2];
        }
    }
    // Handle remaining element if n is odd and i == n-1 was skipped
    if ((n - order) % 2 != 0 && n > order) {
        res[n-1] = smp[n-1] - smp[n-3];
    }
}
