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
for (j = 0; j < N; ++j) {
    int range_start = Ap[j];
    int range_end = Ap[j + 1];
    for (p = range_start; p < range_end; ++p) {
        if (w[Ai[p]] < 0) {
            ATi[0] = j;
        } else {
            int k = w[Ai[p]]++;
            ATi[k] = j;
        }
    }
}
}
