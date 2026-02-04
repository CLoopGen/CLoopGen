#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t M;
extern int *Aj;
extern int *Ap;
extern int *ATj;
extern int *w;
extern int p;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < M; ++i) {
        size_t base = Ap[i];
        size_t limit = Ap[i + 1];
        for (p = base; p < limit; ++p) {
            size_t idx = Aj[p];
            size_t old_val = w[idx];
            w[idx] = old_val + 1;
            ATj[old_val] = i;
        }
    }
}
