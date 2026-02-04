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
    int b = smp[i] - smp[i - 1];
    int d = b - a;
    res[i] = d - c;
    a = smp[i + 1] - smp[i];
    c = a - b;
    res[i + 1] = c - d;
}

}
