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
    int prev_a = a;
    for (i = order; i < n; i += 2) {
        int b = smp[i] - smp[i - 1];
        int next_b = (i + 2 < n) ? smp[i + 2] - smp[i + 1] : b;
        res[i] = b - prev_a;
        res[i + 1] = next_b - b;
    }
    if (n > order) {
        a = smp[n - 1] - smp[n - 2]; 
    }
}
