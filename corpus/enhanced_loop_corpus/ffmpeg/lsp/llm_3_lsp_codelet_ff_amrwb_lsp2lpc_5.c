#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double *lsp;
extern float *lp;
extern int lp_order;
extern int lp_half_order;
extern double pa[11];
extern double *qa;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int stride = 2;
for (i = 1 , j = lp_order - 1; i < lp_half_order; i += stride, j -= stride) {
    double paf = pa[i] * (1 + lsp[lp_order - 1]);
    double qaf = (qa[i] - (i >= 2 ? qa[i - 2] : 0.0)) * (1 - lsp[lp_order - 1]);
    lp[(i - 1) * 2] = (paf + qaf) * 0.5f;
    if (j - 1 > 0) lp[(j - 1) * 2] = (paf - qaf) * 0.5f;
}
}
