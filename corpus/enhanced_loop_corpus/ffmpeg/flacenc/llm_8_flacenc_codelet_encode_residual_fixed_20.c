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
for (i = order; i < n; i += 4) {
    int b1 = smp[i] - smp[i - 1];
    int d1 = b1 - a;
    res[i] = d1 - c;
    int a1 = smp[i + 1] - smp[i];
    int c1 = a1 - b1;
    res[i + 1] = c1 - d1;

    int b2 = smp[i + 2] - smp[i + 1];
    int d2 = b2 - a1;
    res[i + 2] = d2 - c1;
    int a2 = smp[i + 3] - smp[i + 2];
    int c2 = a2 - b2;
    res[i + 3] = c2 - d2;

    a = a2;
    c = c2;
}
}
