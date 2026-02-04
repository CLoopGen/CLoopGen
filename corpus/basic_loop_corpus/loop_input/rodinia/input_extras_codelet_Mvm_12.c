#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>
#include <math.h>

// External variables
int m = 1024;
int n = 512;
int _usr_j0 = 0;
double alpha = 1.5;
double **A;
double *x;
double *y;
int i;
int j;
int m4;
int n2;
double *Aref;
double tmp;

// Helper function to initialize variables
void init_vars() {
    // Derived constants
    m4 = m / 4;
    n2 = n / 2;

    // Allocate x: at least 2*n2 + n (to cover index 2*n2 + j for j in [0, n))
    x = (double*)aligned_alloc(32, sizeof(double) * (2 * n2 + n));
    if (!x) exit(1);

    // Allocate y: total size needed is 4*m4 (first loop) + m (second loop), repeated over n iterations
    // But note: y is being incremented by 4*m4 each outer loop iteration
    // So we need enough space for the entire accumulated offset
    int total_y_size = (4 * m4 + m) * n;
    y = (double*)aligned_alloc(32, sizeof(double) * total_y_size);
    if (!y) exit(1);

    // Initialize y and x with sample data
    for (int idx = 0; idx < total_y_size; idx++) {
        y[idx] = 0.0;
    }
    for (int idx = 0; idx < (2 * n2 + n); idx++) {
        x[idx] = ((double)rand()) / RAND_MAX;
    }

    // Allocate A as a 2D array: rows = (2*n2 + n) + some margin, each row has (4*m4 + m) + margin elements
    int A_rows = 2 * n2 + n + 10;
    int A_row_size = 4 * m4 + m + 10;
    A = (double**)aligned_alloc(32, sizeof(double*) * A_rows);
    if (!A) exit(1);

    for (int row = 0; row < A_rows; row++) {
        A[row] = (double*)aligned_alloc(32, sizeof(double) * A_row_size);
        if (!A[row]) exit(1);
        for (int col = 0; col < A_row_size; col++) {
            A[row][col] = ((double)rand()) / RAND_MAX;
        }
    }

    // Initialize Aref to null (will be set in loop)
    Aref = NULL;
}