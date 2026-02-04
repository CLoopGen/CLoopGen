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
    // Variant 2: Indirect (Gather) Memory Access Pattern
    // Precompute and store valid p indices in a temporary buffer to create an indirect access pattern.
    // Simulate gather-style access by reading all Ai[p] values first, then updating w and ATi indirectly.
    // This changes the access from direct sequential to an indirect, data-dependent pattern.

    // Assuming stack allocation is acceptable for maximum possible size; in practice, this might require dynamic allocation.
    // Here we assume Ap[j+1] - Ap[j] is moderate.
    int *temp_indices = (int*)malloc(N * sizeof(int)); // Conservative upper bound

    for (j = 0; j < N; ++j) {
        size_t length = Ap[j + 1] - Ap[j];
        int *local_temp = temp_indices; // Reuse buffer per j

        // Gather phase: read Ai[p] values contiguously (indirect source)
        for (p = Ap[j]; p < Ap[j + 1]; ++p) {
            local_temp[p - Ap[j]] = Ai[p];
        }

        // Update phase: use gathered indices to update w and ATi
        for (size_t idx = 0; idx < length; ++idx) {
            int ai_val = local_temp[idx];
            int k = w[ai_val]++;
            ATi[k] = j;
        }
    }

    free(temp_indices);
}
