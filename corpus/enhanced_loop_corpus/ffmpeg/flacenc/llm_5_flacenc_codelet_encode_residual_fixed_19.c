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
    for (i = order; i < n; i += 2) {
        int b = smp[i] - smp[i - 1];
        res[i] = (b > 0) ? (b - a) : 0;
        a = smp[i + 1] - smp[i];
        res[i + 1] = (a > b) ? (a - b) : (b - a);
    }
}
