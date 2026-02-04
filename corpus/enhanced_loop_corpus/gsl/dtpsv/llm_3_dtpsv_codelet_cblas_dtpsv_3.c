#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double *Ap;
extern double *X;
extern  int incX;
extern int i;
extern int j;
extern  int nonunit;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Modify memory access pattern to use indirect indexing via an address table for X (simulate gather access)
// Assume auxiliary array of pointers to X elements is available: double * restrict Xptrs[N]
// We simulate strided access through pointer arithmetic stored in an array

// Since we cannot introduce new global declarations, we simulate the idea using a local index mapping
int indices[N];
for (int k = 0; k < N; k++) {
    indices[k] = k * incX;  // Precompute index offsets for X based on stride
}

for (i = N - 1; i > 0 && i--;) {
    double tmp = X[ix];
    int jx = ix + incX;
    for (j = i + 1; j < N; j++) {
        const double Aji = Ap[(((j) * ((j) + 1)) / 2 + (i))];
        tmp -= Aji * X[indices[j]];  // Indirect access to X via precomputed index table
        jx += incX;
    }
    if (nonunit) {
        X[ix] = tmp / Ap[(((i) * ((i) + 1)) / 2 + (i))];
    } else {
        X[ix] = tmp;
    }
    ix -= incX;
}
}
