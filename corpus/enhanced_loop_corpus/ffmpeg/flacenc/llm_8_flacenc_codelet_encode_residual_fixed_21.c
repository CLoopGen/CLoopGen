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
extern int e;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = order; i < n; i += 4) {
    int b1 = smp[i] - smp[i - 1];
    int d1 = b1 - a;
    int f1 = d1 - c;
    res[i] = f1 - e;

    int b2 = smp[i + 1] - smp[i];
    int d2 = b2 - b1;
    int f2 = d2 - d1;
    res[i + 1] = f2 - f1;

    int b3 = smp[i + 2] - smp[i + 1];
    int d3 = b3 - b2;
    int f3 = d3 - d2;
    res[i + 2] = f3 - f2;

    int b4 = smp[i + 3] - smp[i + 2];
    int d4 = b4 - b3;
    int f4 = d4 - d3;
    res[i + 3] = f4 - f3;

    a = b4;
    c = d4;
    e = f4;
}
}
