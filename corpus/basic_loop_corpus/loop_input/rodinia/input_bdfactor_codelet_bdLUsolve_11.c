#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    u_int dim;
    u_int max_dim;
    double *ve;
} VEC;

VEC *x;
int i;
int j;
int l;
int n = 2048;
int n1;
int lb = 1;
int ub = 50;
double c;
double **bA_v;

void init_vars() {
    // Allocate vector x
    x = (VEC*)malloc(sizeof(VEC));
    x->dim = n;
    x->max_dim = n;
    x->ve = (double*)calloc(n, sizeof(double));

    // Set loop bounds to ensure valid access
    n1 = n - 1;
    lb = 1;
    ub = 50;  // Must be <= some reasonable bandwidth

    // Allocate bA_v: we need rows from [lb] to at least [lb + max(j-i)] where j-i < ub
    // Max offset l = lb + (j-i), j goes up to n-1, i down to 0 -> max j-i is ub
    int num_rows = lb + ub + 10;  // extra padding
    bA_v = (double**)calloc(num_rows, sizeof(double*));
    for (int r = 0; r < num_rows; r++) {
        bA_v[r] = (double*)calloc(n, sizeof(double));
        // Initialize with identity-like pattern to avoid division by zero
        if (r == lb) {
            for (int k = 0; k < n; k++) {
                bA_v[r][k] = 1.0;  // diagonal dominance
            }
        } else {
            for (int k = 0; k < n; k++) {
                bA_v[r][k] = ((double)rand() / RAND_MAX) * 0.1;  // small off-diagonals
            }
        }
    }

    // Initialize x->ve with sample values
    for (int idx = 0; idx < n; idx++) {
        x->ve[idx] = (double)rand() / RAND_MAX * 100.0;
    }
}