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
    int prev_smp = smp[i - 1];
    for (i = order; i < n; i += 2) {
        int b = smp[i] - prev_smp;
        int d = b - a;
        int f = d - c;
        res[i] = f - e;
        prev_smp = smp[i];
        int next_a = smp[i + 1] - smp[i];
        int next_c = next_a - b;
        int next_e = next_c - d;
        res[i + 1] = next_e - f;
        a = next_a;
        c = next_c;
        e = next_e;
    }
}
