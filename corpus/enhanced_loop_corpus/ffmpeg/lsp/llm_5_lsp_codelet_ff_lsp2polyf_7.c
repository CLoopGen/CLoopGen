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
for (i = 2; i <= lp_half_order; i++) {
    double val = -2 * lsp[2 * i];
    if (i % 2 == 0) {
        f[i] = val * f[i - 1] + 2 * f[i - 2];
        for (j = i - 1; j > 1; j--)
            f[j] += f[j - 1] * val + f[j - 2];
        f[1] += val;
    } else {
        f[i] = 0.0;
        for (j = i - 1; j > 1; j--)
            f[j] -= f[j - 1] * val;
        f[1] -= val;
    }
}
}
