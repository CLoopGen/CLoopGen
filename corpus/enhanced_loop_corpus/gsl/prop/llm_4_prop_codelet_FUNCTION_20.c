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
    int **data = (int**)malloc(M * sizeof(int*));
    for (i = 0; i < M; i++) {
        data[i] = (int*)calloc(N, sizeof(int));
        for (j = 0; j < N; j++) {
            if (i > 0) {
                data[i][j] = data[i-1][j] + 1; // Introduce loop-carried RAW dependency
            } else {
                data[i][j] = 1;
            }
        }
    }
    free(data[0]);
    free(data);
}
