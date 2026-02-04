#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double alpha;
extern  double *X;
extern  int incX;
extern double *Ap;
extern int i;
extern int j;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Flatten the original two-level loop into a single loop with manual index management
int flat_i = 0;
int flat_j = 0;
int jx;
const double* temp_X_base;
double temp_alpha_val;

for (int idx = 0; idx < ((N * (N + 1)) / 2); idx++) {
    if (flat_j == flat_i) {
        // Start of a new row: initialize variables like outer loop
        temp_alpha_val = alpha * X[flat_i * incX]; // assuming ix starts at 0 and grows by incX
        temp_X_base = &X[flat_i * incX];
    }
    // Compute the correct position in Ap using the same formula
    Ap[((((((flat_i) - 1) + 1) * (2 * (N) - ((flat_i) - 1))) / 2) + (flat_j) - (flat_i))] += temp_X_base[(flat_j - flat_i) * incX] * temp_alpha_val;

    flat_j++;
    if (flat_j >= N) {
        flat_i++;
        flat_j = flat_i;
    }
}
}
