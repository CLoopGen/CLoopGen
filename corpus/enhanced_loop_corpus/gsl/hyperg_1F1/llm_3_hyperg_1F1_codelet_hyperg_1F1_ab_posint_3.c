#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int a;
extern  int b;
extern  double x;
extern double Mnm1;
extern double Mn;
extern double Mnp1;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive array-based accumulation to change memory access pattern
    // Instead of updating scalars iteratively, use an array and traverse consecutively
    if (a <= 1) return;
    double *M = (double*)alloca((a + 2) * sizeof(double));
    // Initialize base cases
    M[0] = Mnm1;
    M[1] = Mn;
    // Consecutive forward access with unit stride
    for (int i = 1; i < a; i++) {
        M[i+1] = ((b - i) * M[i-1] + (2 * i - b + x) * M[i]) / i;
    }
    // Final values after loop
    Mnm1 = M[a-1];
    Mn = M[a];
    Mnp1 = M[a+1];
}
