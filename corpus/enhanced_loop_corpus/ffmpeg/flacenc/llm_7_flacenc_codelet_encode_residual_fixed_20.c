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
    int prev_a = a;
    int prev_c = c;
    for (i = order; i < n; i += 2) {
        int b = smp[i] - smp[i - 1];
        int d = b - prev_a;
        res[i] = d - prev_c;
        int next_a = smp[i + 1] - smp[i];
        int next_c = next_a - b;
        if (i + 2 < n) {
            res[i + 1] = next_c - d;
        }
        prev_a = next_a;
        prev_c = next_c;
    }
    // Final update to global state
    a = prev_a;
    c = prev_c;
}
