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
        int range = Ap[i + 1] - Ap[i];
        for (p = Ap[i]; p < Ap[i + 1]; p += 4) {
            size_t k0, k1, k2, k3;
            if (p < Ap[i + 1]) {
                k0 = w[Aj[p]]++;
                ATj[k0] = i;
            }
            if (p + 1 < Ap[i + 1]) {
                k1 = w[Aj[p + 1]]++;
                ATj[k1] = i;
            }
            if (p + 2 < Ap[i + 1]) {
                k2 = w[Aj[p + 2]]++;
                ATj[k2] = i;
            }
            if (p + 3 < Ap[i + 1]) {
                k3 = w[Aj[p + 3]]++;
                ATj[k3] = i;
            }
        }
    }
}
