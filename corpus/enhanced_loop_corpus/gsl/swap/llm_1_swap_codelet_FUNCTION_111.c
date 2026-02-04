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
        for (int offset = 0; offset < (Ap[i + 1] - Ap[i]); ++offset) {
            p = Ap[i] + offset;
            size_t k = w[Aj[p]]++;
            ATj[k] = i;
        }
    }
}
