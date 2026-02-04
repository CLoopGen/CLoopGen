#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    double re;
    double im;
} complex;

int i;
int j;
int lo;
int hi;
int k;
complex **A_me;
complex tmp;

void init_vars() {
    const int num_rows = 1 << 14; // 16384 rows
    const int num_cols = 128;      // 128 columns per row
    const size_t total_size = (size_t)num_rows * num_cols * sizeof(complex);

    // Ensure ~0.01 sec runtime: adjust problem size if needed, but this should be in the right range

    // Allocate array of pointers
    A_me = (complex**)calloc(num_rows, sizeof(complex*));
    if (!A_me) exit(1);

    // Allocate each row
    for (int r = 0; r < num_rows; r++) {
        A_me[r] = (complex*)calloc(num_cols, sizeof(complex));
        if (!A_me[r]) exit(1);
        // Initialize with non-zero values to make swaps observable
        for (int c = 0; c < num_cols; c++) {
            A_me[r][c].re = (double)(r + c);
            A_me[r][c].im = (double)(r - c);
        }
    }

    // Set valid column indices within [0, num_cols-1]
    i = 10;
    j = 20;

    // Set loop bounds within [0, num_rows-1]
    lo = 0;
    hi = num_rows - 1;
}