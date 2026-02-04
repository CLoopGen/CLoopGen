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
for (i = 1; i <= lp_half_order; i++) {
    double val = -lsp[2 * i];
    f[i] = val * f[i - 1];
    for (j = i; j > 1; j--)
        f[j] += f[j - 1] * val;
}
}
