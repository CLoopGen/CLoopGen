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
    for (i = order + 1; i < n - 1; i += 4) {
        int b1 = smp[i] - smp[i - 1];
        int b2 = smp[i + 1] - smp[i];
        res[i] = b1 - a;
        res[i + 1] = b2 - b1;
        int temp_a = smp[i + 2] - smp[i + 1];
        res[i + 2] = temp_a - b2;
        a = smp[i + 3] - smp[i + 2];
        res[i + 3] = a - temp_a;
    }
}
