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
        int current_b = smp[i] - smp[i - 1];
        int current_d = current_b - a;
        int current_f = current_d - c;
        res[i] = current_f - e;

        int next_b = smp[i + 1] - smp[i];
        int next_d = next_b - current_b;
        int next_f = next_d - current_d;
        int next_g = next_f - current_f;
        res[i + 1] = next_g;

        a = next_b;
        c = next_d;
        e = next_f;
    }
}
