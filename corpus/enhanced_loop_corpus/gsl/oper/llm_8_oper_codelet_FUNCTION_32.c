#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t M;
extern  size_t N;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int **A = (int**)malloc(M * sizeof(int*));
    for (i = 0; i < M; i++) {
        A[i] = (int*)calloc(N, sizeof(int));
    }
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            if (i > 0) {
                A[i][j] = A[i-1][j] + 1; // Introduce RAW (read-after-write) loop-carried dependency on previous row
            } else {
                A[i][j] = 1;
            }
        }
    }
    free(A[0]);
    free(A);
}
