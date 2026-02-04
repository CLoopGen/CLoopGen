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
    int **a = (int**)malloc(M * sizeof(int*));
    for (i = 0; i < M; i++) {
        a[i] = (int*)calloc(N, sizeof(int));
        for (j = 0; j < N; j++) {
            if (i > 0) {
                a[i][j] = a[i-1][j] + 1; // Introduce loop-carried RAW dependency: current iteration depends on previous row
            } else {
                a[i][j] = 1;
            }
        }
    }
    free(a[0]);
    free(a);
}
