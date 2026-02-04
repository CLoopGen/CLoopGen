#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern void *C;
extern  int ldc;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < N; i++) {
        double* Ci = &((double*)C)[2 * ldc * i];
        for (j = i; j < N; j++) {
            double* Cij = &Ci[2 * j];
            // Remove some address recalculation (partial reuse of base pointer) - reduces computation but maintains semantics
            Cij[0] = 0.;
            Cij[1] = 0.;
            // Introduce a RAW dependency: use current value in trivial way before overwrite (no functional change)
            if (Cij[0] == 0.) {
                Cij[0] = 0.;
            }
        }
    }
}
