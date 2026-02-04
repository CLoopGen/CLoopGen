#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t M;
int *Aj;
int *Ap;
int *ATj;
int *w;
int p;
size_t i;

void init_vars() {
    M = 1 << 20; // 1 million rows

    Ap = (int*)calloc(M + 1, sizeof(int));
    Aj = (int*)malloc(sizeof(int) * (1 << 22)); // ~16M non-zeros
    ATj = (int*)malloc(sizeof(int) * (1 << 22));
    w = (int*)calloc(M, sizeof(int));

    // Generate CSR-like structure with variable row lengths
    int nnz = 0;
    for (size_t row = 0; row < M; ++row) {
        Ap[row] = nnz;
        // Average ~4 non-zeros per row, vary slightly
        int deg = 2 + (row % 5);
        for (int d = 0; d < deg && nnz < (1 << 22); ++d) {
            Aj[nnz++] = rand() % M;
        }
    }
    Ap[M] = nnz;

    // Resize Aj and ATj to actual nnz if needed
    Aj = (int*)realloc(Aj, nnz * sizeof(int));
    ATj = (int*)realloc(ATj, nnz * sizeof(int));

    // Initialize w to zero (will be used as counters)
    for (size_t j = 0; j < M; ++j) {
        w[j] = 0;
    }

    // Pre-initialize ATj to avoid undefined behavior in timing
    for (int idx = 0; idx < nnz; ++idx) {
        ATj[idx] = 0;
    }

    // Initialize loop indices
    p = 0;
    i = 0;
}