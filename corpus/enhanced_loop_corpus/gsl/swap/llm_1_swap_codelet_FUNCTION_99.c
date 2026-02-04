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
    size_t total_iters = 0;
    for (j = 0; j < N; ++j) {
        total_iters += (Ap[j + 1] - Ap[j]);
    }
    size_t idx = 0;
    for (j = 0; j < N && idx < total_iters; ++j) {
        for (p = Ap[j]; p < Ap[j + 1]; ++p, ++idx) {
            int k = w[Ai[p]]++;
            ATi[k] = j;
        }
    }
}
