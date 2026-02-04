#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    double re;
    double im;
} complex;

typedef struct {
    u_int m;
    u_int n;
    u_int max_m;
    u_int max_n;
    u_int max_size;
    complex *base;
    complex **me;
} ZMAT;

extern ZMAT *A;
extern int i;
extern int j;
extern complex **A_me;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Consecutive memory access via linear indexing
    // Flatten the 2D access pattern into a pseudo 1D traversal to improve cache locality.
    // We calculate the total number of elements accessed and iterate consecutively,
    // converting linear index back to row and column indices.

    u_int total_elements = 0;
    for (u_int temp_i = 1; temp_i < A->m; temp_i++) {
        total_elements += (temp_i > 0) ? temp_i - 1 : 0;
    }

    u_int idx = 0;
    for (u_int linear = 0; linear < total_elements; linear++) {
        // Compute corresponding i and j from linear index
        u_int row = 1;
        u_int count_up_to_row = 0;
        while (count_up_to_row + (row - 1) <= linear && row < A->m) {
            count_up_to_row += row - 1;
            row++;
        }
        i = row;
        j = linear - count_up_to_row;

        A_me[i][j].re = 0.;
        A_me[i][j].im = 0.;
    }
}
