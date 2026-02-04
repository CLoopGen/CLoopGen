#include <stdio.h>
#include <inttypes.h>

int n = 1000;
int m = 7;
double C[1200][1200];
int i;
int j;

void init_vars() {
    // Ensure n does not exceed array bounds
    if (n > 1200) {
        n = 1200;
    }
    // Initialize array to zero or predictable value if needed
    for (int ii = 0; ii < n; ii++) {
        for (int jj = 0; jj < n; jj++) {
            C[ii][jj] = 0.0;
        }
    }
}