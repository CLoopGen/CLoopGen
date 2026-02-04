#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double *lsp;
extern double *f;
extern int lp_half_order;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
double prev_f1 = f[1];
for (i = 2; i <= lp_half_order; i++) {
    double val = -2 * lsp[2 * i];
    f[i] = val * f[i - 1] + 2 * f[i - 2];
    for (j = 2; j < i; j++) {
        int idx = i - j + 1;
        if (idx > 1) {
            f[idx] += f[idx - 1] * val + f[idx - 2];
        }
    }
    prev_f1 += val;
}
f[1] = prev_f1;
}
