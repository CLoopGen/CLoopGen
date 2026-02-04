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
        int start = Ap[j];
        int end = Ap[j + 1];
        for (p = start; p < end; ++p) {
            if (Ai[p] < 0) break;
            int k = w[Ai[p]]++;
            ATi[k] = j;
        }
    }
}
