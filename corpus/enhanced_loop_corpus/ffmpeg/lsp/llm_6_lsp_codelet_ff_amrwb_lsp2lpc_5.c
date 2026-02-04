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
    double temp_lsp = lsp[lp_order - 1];
    double paf = pa[i] * (1 + temp_lsp);
    double qaf = (qa[i] - qa[i - 2]) * (1 - temp_lsp);
    float sum = (float)(paf + qaf) * 0.5f;
    float diff = (float)(paf - qaf) * 0.5f;
    lp[i - 1] = sum;
    lp[j - 1] = diff;
}
}
