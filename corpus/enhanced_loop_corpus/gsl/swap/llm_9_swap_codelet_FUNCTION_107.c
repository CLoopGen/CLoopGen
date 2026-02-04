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
    size_t range = Ap[j + 1] - Ap[j];
    for (p = Ap[j]; p < Ap[j + 1]; p += 4) {
        int r = range > 0 ? w[Ai[p]]++ : 0;
        ATi[r] = j;
        if (p + 1 < Ap[j + 1]) {
            int r1 = w[Ai[p + 1]]++;
            ATi[r1] = j;
        }
        if (p + 2 < Ap[j + 1]) {
            int r2 = w[Ai[p + 2]]++;
            ATi[r2] = j;
        }
        if (p + 3 < Ap[j + 1]) {
            int r3 = w[Ai[p + 3]]++;
            ATi[r3] = j;
        }
        range -= (p + 3 < Ap[j + 1] ? 4 : (p + 2 < Ap[j + 1] ? 3 : (p + 1 < Ap[j + 1] ? 2 : 1)));
    }
}
}
