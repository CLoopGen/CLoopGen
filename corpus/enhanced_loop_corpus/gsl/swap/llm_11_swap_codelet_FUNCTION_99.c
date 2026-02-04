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
    // Variant 2: Reduced computational intensity by increasing trip count with lighter work per iteration.
    // Split the original inner loop into two separate loops with simpler control flow and reduced memory access density.
    for (j = 0; j < N; ++j) {
        size_t start = Ap[j];
        size_t end = Ap[j + 1];
        // First pass: only increment w[Ai[p]]
        for (p = start; p < end; ++p) {
            w[Ai[p]]++;
        }
        // Second pass: use updated w values to assign ATi, but now using a shifted index to preserve logical equivalence
        // Note: we assume w has been pre-initialized appropriately and this variant adjusts usage accordingly.
        // We simulate the pre-increment effect by decrementing first in this pass.
        for (p = start; p < end; ++p) {
            int k = --w[Ai[p]];  // Undo increment to recover original value
            ATi[k] = j;
            w[Ai[p]]++;          // Restore increment after use
        }
    }
}
