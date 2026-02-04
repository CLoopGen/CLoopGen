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
        if (smp[i] >= smp[i - 1]) {
            int b = smp[i] - smp[i - 1];
            res[i] = b - a;
            a = smp[i + 1] - smp[i];
            res[i + 1] = a - b;
        } else {
            res[i] = 0;
            res[i + 1] = 0;
        }
    }
}
