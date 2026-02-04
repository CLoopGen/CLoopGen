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
    for (i = 0; i < M; i += 2) {
        size_t i1 = i;
        size_t i2 = i + 1;
        if (i1 < M) {
            for (p = Ap[i1]; p < Ap[i1 + 1]; ++p) {
                size_t k = w[Aj[p]]++;
                ATj[k] = i1;
            }
        }
        if (i2 < M) {
            for (p = Ap[i2]; p < Ap[i2 + 1]; ++p) {
                size_t k = w[Aj[p]]++;
                ATj[k] = i2;
            }
        }
    }
}
