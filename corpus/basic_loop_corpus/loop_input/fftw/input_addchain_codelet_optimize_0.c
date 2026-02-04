#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int n;
int *A;
int i;
int cst;
int cstmax;

static int *A_data = NULL;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // ~64 MB to target ~0.01 sec on modern CPU
    n = data_size / sizeof(int);
    
    A_data = (int*)aligned_alloc(32, n * sizeof(int));
    if (!A_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    A = A_data;

    for (int j = 0; j < n; ++j) {
        A[j] = rand() % 1000 - 500; // Random values in [-500, 499]
    }

    cst = 0;
    cstmax = -1000;
}