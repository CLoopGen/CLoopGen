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
    if (N == 0) return;
    for (j = 0; j < N; ++j) {
        p = Ap[j];
        while (p < Ap[j + 1]) {
            int k = w[Ai[p]]++;
            ATi[k] = j;
            ++p;
        }
    }
}
