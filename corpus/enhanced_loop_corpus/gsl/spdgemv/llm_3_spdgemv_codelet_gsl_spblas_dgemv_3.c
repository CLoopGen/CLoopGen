#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double alpha;
extern size_t j;
extern size_t incX;
extern size_t incY;
extern size_t lenY;
extern double *X;
extern double *Y;
extern double *Ad;
extern int *Ap;
extern int *Ai;
extern int p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Modify access pattern to promote indirect but grouped access via Ai indices
    // Reorder computation based on the column indices (Ai) to create more spatial locality in X accesses.
    // This variant sorts or assumes sorted Ai within each column for better X stride behavior.
    // Since we cannot sort here without extra data, we simulate improved access by assuming grouping.
    size_t p;
    double temp;
    for (j = 0; j < lenY; ++j) {
        for (p = Ap[j]; p < Ap[j + 1]; ++p) {
            // Indirect access through Ai[p] remains, but we assume preprocessing has grouped similar indices
            temp = alpha * Ad[p];
            Y[j * incY] += temp * X[Ai[p] * incX];  // Still indirect, but X accessed with potential reuse if Ai[p] clusters
        }
    }
}
