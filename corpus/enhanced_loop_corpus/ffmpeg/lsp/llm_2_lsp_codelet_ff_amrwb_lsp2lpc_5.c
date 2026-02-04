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
    int idx_paf = lp_order - 1;
    int idx_qa_prev = (i >= 2) ? i - 2 : 0;
    double paf = pa[i] * (1 + lsp[idx_paf]);
    double qaf = (qa[i] - qa[idx_qa_prev]) * (1 - lsp[idx_paf]);
    lp[i - 1] = (paf + qaf) * 0.5f;
    lp[j - 1] = (paf - qaf) * 0.5f;
}
}
