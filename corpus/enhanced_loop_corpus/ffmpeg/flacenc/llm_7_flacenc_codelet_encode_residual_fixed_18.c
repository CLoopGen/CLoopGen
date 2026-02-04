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
    for (i = order; i < n; i += 2) {
        if (i + 1 < n) {
            res[i] = smp[i] - smp[i - 1];
            res[i + 1] = smp[i + 1] - smp[i];
        } else {
            res[i] = smp[i] - smp[i - 1];
        }
    }
}
