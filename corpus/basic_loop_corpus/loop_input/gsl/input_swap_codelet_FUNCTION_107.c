#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t N = 100000;
int *Ai;
int *Ap;
int *ATi;
int *w;

int p;
size_t j;

void init_vars() {
    // Allocate Ap: length N+1
    Ap = (int*)calloc(N + 1, sizeof(int));
    
    // Generate degree for each row: average about 5-10 nonzeros per row to get reasonable total size
    int avg_nnz_per_row = 8;
    int total_nnz = N * avg_nnz_per_row;
    
    // Fill Ap as CSR row pointers: Ap[0]=0, Ap[i] = Ap[i-1] + degree[i-1]
    for (size_t i = 0; i <= N; ++i) {
        Ap[i] = (i == 0) ? 0 : Ap[i-1] + (rand() % 16 + 4); // Random degree between 4 and 19
    }
    
    // In case randomness caused overflow, clamp and fix
    if (Ap[N] > total_nnz * 2) Ap[N] = total_nnz * 2;
    total_nnz = Ap[N];
    
    // Allocate Ai (column indices), ATi (transposed column indices), and w (counters)
    Ai = (int*)malloc(total_nnz * sizeof(int));
    ATi = (int*)malloc(total_nnz * sizeof(int));
    w = (int*)malloc(N * sizeof(int));
    
    // Initialize Ai with valid column indices in [0, N)
    for (int i = 0; i < total_nnz; ++i) {
        Ai[i] = rand() % N;
    }
    
    // Initialize w to zero
    for (size_t i = 0; i < N; ++i) {
        w[i] = 0;
    }
}