#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ptrdiff_t INT;

typedef struct {
    INT n;
    INT is;
    INT os;
} iodim;

typedef struct {
    int rnk;
    iodim dims[1];
} tensor;

int rnk = 5;
int *n;
int *niphys;
int *nophys;
tensor *x;
int i;

void init_vars() {
    // Allocate arrays based on rnk
    n = (int*)calloc(rnk, sizeof(int));
    niphys = (int*)calloc(rnk, sizeof(int));
    nophys = (int*)calloc(rnk, sizeof(int));

    // Initialize array values to ensure valid memory access and meaningful computation
    for (int idx = 0; idx < rnk; ++idx) {
        n[idx] = 16;
        niphys[idx] = 2;
        nophys[idx] = 2;
    }

    // Allocate tensor x with flexible array member large enough for rnk dimensions
    x = (tensor*)malloc(sizeof(tensor) + (rnk - 1) * sizeof(iodim));
    x->rnk = rnk;

    // Initialize last dimension
    x->dims[rnk - 1].is = 1;
    x->dims[rnk - 1].os = 1;
    x->dims[rnk - 1].n = n[rnk - 1];

    // Pre-initialize other dims if needed, though loop will overwrite them
    for (int idx = 0; idx < rnk - 1; ++idx) {
        x->dims[idx].n = n[idx];
        x->dims[idx].is = 1;
        x->dims[idx].os = 1;
    }
}