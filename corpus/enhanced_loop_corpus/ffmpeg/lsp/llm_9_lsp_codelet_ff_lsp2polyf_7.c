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
for (i = 3; i <= lp_half_order; i += 2) {
    double val = -2 * lsp[2 * i] * lsp[2 * i - 1];
    double temp1 = f[i - 1];
    double temp2 = f[i - 2];
    f[i] = val * temp1 + 2 * temp2 - temp1 * temp2;
    for (j = i - 1; j > 2; j--) {
        f[j] += f[j - 1] * val + f[j - 2];
        f[j - 1] -= f[j - 2] * val;
    }
    f[2] += val;
    f[1] += val * 0.5;
}
}
