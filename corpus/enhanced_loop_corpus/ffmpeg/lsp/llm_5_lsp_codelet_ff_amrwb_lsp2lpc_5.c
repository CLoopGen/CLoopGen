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
    double paf, qaf;
    if (lsp[lp_order - 1] > 0.0) {
        paf = pa[i] * (1 + lsp[lp_order - 1]);
        qaf = (qa[i] - qa[i - 2]) * (1 - lsp[lp_order - 1]);
    } else {
        paf = pa[i];
        qaf = qa[i] - qa[i - 2];
    }
    lp[i - 1] = (paf + qaf) * 0.5;
    lp[j - 1] = (paf - qaf) * 0.5;
}
}
