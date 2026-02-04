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
extern int c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = order; i < n; i += 2) {
        int temp1 = smp[i] - smp[i - 1];
        int temp2 = temp1 - a;
        res[i] = temp2 - c;
        int temp3 = smp[i + 1] - smp[i];
        int temp4 = temp3 - temp1;
        res[i + 1] = temp4 - temp2;
        a = temp3;
        c = temp4;
    }
}
