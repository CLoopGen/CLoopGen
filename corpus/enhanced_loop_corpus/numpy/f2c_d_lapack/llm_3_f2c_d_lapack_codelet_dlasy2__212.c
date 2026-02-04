#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer i__;
extern integer j;
extern integer k;
extern doublereal t16[16];
extern doublereal tmp[4];
extern doublereal btmp[4];
extern doublereal temp;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Strided Memory Access Pattern with Reverse Traversal Simulation
    // Use strided access by introducing a stride variable and reverse iteration via arithmetic
    // Access arrays using a fixed stride pattern, simulating non-unit stride behavior.
    const integer stride = 5;  // Logical row/column stride in t16 interpreted as 5x5 matrix
    for (i__ = 4; i__ >= 1; --i__) {  // Reverse loop direction
        k = 5 - i__;
        integer idx_k = k - 1;
        integer t_idx_kk = (k-1)*stride + (k-1);  // Map 2D-like (k,k) to 1D with stride
        temp = 1. / t16[t_idx_kk];
        tmp[idx_k] = btmp[idx_k] * temp;
        for (j = k + 1; j <= 4; ++j) {
            integer t_idx_kj = (k-1)*stride + (j-1);  // Strided access: t16[k-1][j-1]
            tmp[idx_k] -= temp * t16[t_idx_kj] * tmp[j - 1];
        }
    }
}
