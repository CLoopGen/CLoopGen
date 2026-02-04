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
        if (i + 1 < M) {
            int p1, p2;
            for (p1 = Ap[i], p2 = Ap[i + 1]; p1 < Ap[i + 1] || p2 < Ap[i + 2]; ) {
                if (p1 < Ap[i + 1]) {
                    size_t k = w[Aj[p1]]++;
                    ATj[k] = i;
                    ++p1;
                }
                if (p2 < Ap[i + 2]) {
                    size_t k = w[Aj[p2]]++;
                    ATj[k] = i + 1;
                    ++p2;
                }
            }
        } else {
            for (p = Ap[i]; p < Ap[i + 1]; ++p) {
                size_t k = w[Aj[p]]++;
                ATj[k] = i;
            }
        }
    }
}
