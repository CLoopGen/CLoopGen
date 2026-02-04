#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double beta;
extern double A[2000][2000];
extern double x[2000];
extern double y[2000];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Memory Access Pattern Modification - Use strided access with reverse traversal
    // Instead of accessing A[j][i] in column-major-like order, we reverse the inner loop and stride by 2
    // to create a non-unit strided access pattern on y[j] and A[j][i]
    for (i = 0; i < n; i++) {
        double temp = x[i];
        for (j = n - 1; j >= 0; j -= 2) {
            temp += beta * A[j][i] * y[j];
            if (j > 0) {
                temp += beta * A[j-1][i] * y[j-1];
            }
        }
        x[i] = temp;
    }
}
