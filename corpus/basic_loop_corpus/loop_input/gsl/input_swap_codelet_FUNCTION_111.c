#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t M = 1 << 20; // 1 million rows
size_t nnz = 4 << 20; // 4 million non-zeros

int *Aj = NULL;
int *Ap = NULL;
int *ATj = NULL;
int *w = NULL;

int p;
size_t i;

void init_vars() {
    Aj = (int*)calloc(nnz, sizeof(int));
    Ap = (int*)malloc((M + 1) * sizeof(int));
    ATj = (int*)malloc(nnz * sizeof(int));
    w = (int*)calloc(M, sizeof(int));

    // Initialize Ap: random-ish but valid CSR format
    Ap[0] = 0;
    for (size_t i = 1; i <= M; ++i) {
        // Average ~4 entries per row
        Ap[i] = Ap[i-1] + (rand() % 8 + 1);
        if (Ap[i] > nnz) {
            Ap[i] = nnz;
        }
    }

    // Initialize Aj with valid column indices
    for (size_t j = 0; j < nnz; ++j) {
        Aj[j] = rand() % M;
    }

    // Initialize w to zero (already done by calloc)
}
// End of file