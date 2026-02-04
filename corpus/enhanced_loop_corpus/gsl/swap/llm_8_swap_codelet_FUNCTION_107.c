#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t N;
extern int *Ai;
extern int *Ap;
extern int *ATi;
extern int *w;
extern int p;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < N; j += 2) {
    if (j + 1 < N) {
        int ap_j, ap_j1, ap_next_j, ap_next_j1;
        ap_j = Ap[j];
        ap_j1 = Ap[j + 1];
        ap_next_j = Ap[j + 1];
        ap_next_j1 = Ap[j + 2];
        for (p = ap_j; p < ap_next_j1; ++p) {
            int idx = (p < ap_j1) ? j : j + 1;
            if (p >= ap_next_j) idx = j + 1;
            int k = w[Ai[p]]++;
            ATi[k] = idx;
        }
    } else {
        for (p = Ap[j]; p < Ap[j + 1]; ++p) {
            int k = w[Ai[p]]++;
            ATi[k] = j;
        }
    }
}
}
