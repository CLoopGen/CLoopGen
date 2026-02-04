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
    double temp1 = f[i - 1];
    double temp2 = f[i - 2];
    f[i] = val * temp1 + 2 * temp2;
    for (j = i - 1; j > 1; j--) {
        double prev_val = f[j - 1];
        f[j] += prev_val * val + f[j - 2];
    }
    f[1] += val;
}
}
