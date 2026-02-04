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
    double temp_alpha = alpha;
    int local_mark = mark;
    size_t local_nz = nz;
    for (p = Ap[j]; p < Ap[j + 1]; ++p) {
        size_t i = Ai[p];
        double scaled_val = temp_alpha * Ad[p];
        if (w[i] == local_mark) {
            x[i] += scaled_val;
        } else {
            w[i] = local_mark;
            Ci[local_nz++] = i;
            x[i] = scaled_val;
        }
    }
    nz = local_nz;
    alpha = temp_alpha;
}
