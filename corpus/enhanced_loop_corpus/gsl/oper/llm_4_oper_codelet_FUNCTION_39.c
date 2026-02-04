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
        a[i] = (int*)malloc(N * sizeof(int));
        for (j = 0; j < N; j++) {
            a[i][j] = i + j;
        }
    }
    for (i = 0; i < M; i++) {
        free(a[i]);
    }
    free(a);
}
