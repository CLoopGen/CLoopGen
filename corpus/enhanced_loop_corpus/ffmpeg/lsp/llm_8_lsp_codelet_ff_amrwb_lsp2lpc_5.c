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
for (i = 1 , j = lp_order - 1; i < lp_half_order; i++ , j--) {
    double lsp_val = lsp[lp_order - 1];
    double coef1 = 1.0 + lsp_val;
    double coef2 = 1.0 - lsp_val;
    double paf = pa[i] * coef1;
    double qaf = (qa[i] - (i >= 2 ? qa[i - 2] : 0)) * coef2;
    lp[i - 1] = (paf + qaf) * 0.5;
    if (j - 1 != i - 1) {
        lp[j - 1] = (paf - qaf) * 0.5;
    }
}
}
