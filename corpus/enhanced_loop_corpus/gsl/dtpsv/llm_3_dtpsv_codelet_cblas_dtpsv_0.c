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
    // Variant 2: Indirect (Indexed) Memory Access Pattern
    // Replace direct indexing arithmetic with an index array for indirect addressing of X
    int *index_map = (int*)malloc(N * sizeof(int));
    for (int k = 0; k < N; k++) {
        index_map[k] = k * incX;
    }

    for (i = N - 1; i > 0 && i--;) {
        double tmp = X[index_map[i]];
        int j_idx = i + 1;
        for (j = i + 1; j < N; j++) {
            const double Aij = Ap[((((((i) - 1) + 1) * (2 * (N) - ((i) - 1))) / 2) + (j) - (i))];
            tmp -= Aij * X[index_map[j_idx]];
            j_idx++;
        }
        if (nonunit) {
            X[index_map[i]] = tmp / Ap[((((((i) - 1) + 1) * (2 * (N) - ((i) - 1))) / 2) + (i) - (i))];
        } else {
            X[index_map[i]] = tmp;
        }
    }

    free(index_map);
    // Adjust ix to reflect final position after backward traversal
    ix = index_map[N - 1] - incX; // approximate final decrement
}
