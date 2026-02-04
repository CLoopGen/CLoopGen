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
    for (i = order; i < n; i += 2) {
        int skip_first = (i == order);
        int b = smp[i] - smp[i - 1];
        int d = b - a;
        int f = d - c;
        if (!skip_first) {
            res[i] = f - e;
        }
        a = smp[i + 1] - smp[i];
        c = a - b;
        e = c - d;
        if (i + 1 < n) {
            res[i + 1] = e - f;
        }
    }
}
