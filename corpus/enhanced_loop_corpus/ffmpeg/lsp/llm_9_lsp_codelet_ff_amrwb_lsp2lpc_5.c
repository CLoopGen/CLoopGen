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
    double lsp_val = lsp[lp_order - 1];
    double paf1 = pa[i] * (1 + lsp_val);
    double qaf1 = (qa[i] - (i >= 2 ? qa[i - 2] : 0)) * (1 - lsp_val);
    lp[i - 1] = (paf1 + qaf1) * 0.5;
    if (i + 1 < lp_half_order) {
        double paf2 = pa[i + 1] * (1 + lsp_val);
        double qaf2 = (qa[i + 1] - (i >= 1 ? qa[i - 1] : 0)) * (1 - lsp_val);
        lp[i] = (paf2 + qaf2) * 0.5;
        int j2 = j - 1;
        lp[j - 1] = (paf1 - qaf1) * 0.5;
        if (j2 - 1 >= 0) lp[j2 - 1] = (paf2 - qaf2) * 0.5;
    } else {
        lp[j - 1] = (paf1 - qaf1) * 0.5;
    }
}
}
