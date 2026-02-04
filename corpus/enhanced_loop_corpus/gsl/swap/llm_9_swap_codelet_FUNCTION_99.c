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
        int local_update = 0;
        for (p = Ap[j]; p < Ap[j + 1]; ++p) {
            int neighbor = Ai[p];
            // Remove WAW hazard by deferring write to w until after loop
            int temp_k = w[neighbor] + local_update;
            ATi[temp_k] = j;
            local_update += 1;
        }
        // Apply batch increment to avoid intra-loop write conflicts
        for (p = Ap[j]; p < Ap[j + 1]; ++p) {
            w[Ai[p]]++;
        }
    }
}
