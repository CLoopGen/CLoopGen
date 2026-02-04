#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

typedef int logical;

extern integer *m;
extern integer *n;
extern real *alpha;
extern real *a;
extern real *b;
extern integer a_dim1;
extern integer b_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern integer k;
extern real temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Change memory access to consecutive (cache-friendly) by transposing working blocks
    // Simulate a blocking strategy where we work on transposed subblocks to enable consecutive writes.
    // Here, instead of column-major updates, we pull data into a temporary row-major buffer,
    // process it with unit stride, then write back.

    // Temporary buffer to hold transposed block of b columns [1..k] for rows 1..m
    real *temp_block = (real*)malloc(*m * (*n) * sizeof(real));
    if (!temp_block) return;  // Handle allocation failure

    // Transpose relevant portion of b into temp_block (row i, col k -> temp_block[k + i*n])
    for (j = 1; j <= *n; ++j) {
        for (i__ = 1; i__ <= *m; ++i__) {
            temp_block[j - 1 + (i__ - 1) * (*n)] = b[i__ + j * b_dim1];
        }
    }

    // Now perform the algorithm using consecutive access in transposed layout
    for (k = *n; k >= 1; --k) {
        real *b_k_row = &temp_block[(k - 1)];  // Row vector for original column k, now stored consecutively

        if (nounit) {
            temp = 1.F / a[k + k * a_dim1];
            i__1 = *m;
            for (i__ = 1; i__ <= i__1; ++i__) {
                b_k_row[(i__ - 1) * (*n)] = temp * b_k_row[(i__ - 1) * (*n)];  // Consecutive in transformed space
            }
        }

        i__1 = k - 1;
        for (j = 1; j <= i__1; ++j) {
            if (a[j + k * a_dim1] != 0.F) {
                temp = a[j + k * a_dim1];
                real *b_j_row = &temp_block[(j - 1)];
                i__2 = *m;
                for (i__ = 1; i__ <= i__2; ++i__) {
                    int idx = (i__ - 1) * (*n);
                    b_j_row[idx] -= temp * b_k_row[idx];  // Unit-stride arithmetic in blocked layout
                }
            }
        }

        if (*alpha != 1.F) {
            i__1 = *m;
            for (i__ = 1; i__ <= i__1; ++i__) {
                int idx = (i__ - 1) * (*n);
                b_k_row[idx] = *alpha * b_k_row[idx];
            }
        }
    }

    // Transpose back to original column-major format
    for (j = 1; j <= *n; ++j) {
        for (i__ = 1; i__ <= *m; ++i__) {
            b[i__ + j * b_dim1] = temp_block[j - 1 + (i__ - 1) * (*n)];
        }
    }

    free(temp_block);
}
