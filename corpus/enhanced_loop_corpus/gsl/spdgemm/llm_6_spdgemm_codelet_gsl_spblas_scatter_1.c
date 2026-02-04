#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t j;
extern  double alpha;
extern int *w;
extern double *x;
extern  int mark;
extern size_t nz;
extern int p;
extern int *Ai;
extern int *Ap;
extern double *Ad;
extern int *Ci;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t base_nz = nz;
    for (p = Ap[j]; p < Ap[j + 1]; ++p) {
        size_t i = Ai[p];
        if (w[i] < mark) {
            w[i] = mark;
            Ci[base_nz] = i;
            x[i] = alpha * Ad[p];
            base_nz++;
        } else {
            x[i] += alpha * Ad[p];
        }
    }
    nz = base_nz;
}
