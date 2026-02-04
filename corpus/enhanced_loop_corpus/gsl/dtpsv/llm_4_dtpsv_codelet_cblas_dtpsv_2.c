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
// Variant 2: Strided but reversed access pattern for X with direct offset calculation
// Use negative stride simulation even when incX is positive, accessing in reverse order
int effective_incX = (incX > 0) ? incX : -incX;
int start_offset = (incX > 0) ? 0 : (N - 1) * (-incX);

for (i = 1; i < N; i++) {
    int current_ix = start_offset + i * effective_incX;
    double tmp = X[current_ix];
    int jx = start_offset;

    for (j = 0; j < i; j++) {
        const double Aji = Ap[((((((j) - 1) + 1) * (2 * (N) - ((j) - 1))) / 2) + (i) - (j))];
        tmp -= Aji * X[jx];
        jx += effective_incX;
    }

    if (nonunit) {
        double diag = Ap[((((((i) - 1) + 1) * (2 * (N) - ((i) - 1))) / 2) + (i) - (i))];
        X[current_ix] = tmp / diag;
    } else {
        X[current_ix] = tmp;
    }
}
}
