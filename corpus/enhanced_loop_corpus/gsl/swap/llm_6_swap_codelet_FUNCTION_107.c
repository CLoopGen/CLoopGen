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
        int base = Ap[j];
        int limit = Ap[j + 1];
        for (p = base; p < limit; ++p) {
            int temp_index = Ai[p];
            int old_val = w[temp_index];
            w[temp_index] = old_val + 1;
            ATi[old_val] = j;
        }
    }
}
