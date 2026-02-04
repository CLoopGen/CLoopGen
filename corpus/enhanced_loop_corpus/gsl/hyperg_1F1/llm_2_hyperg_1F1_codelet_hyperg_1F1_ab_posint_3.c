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
    // Variant 1: Strided memory access pattern simulation using array-like indexing
    // We simulate strided access by treating scalar variables as elements of a logical array with stride 2
    double M[3]; // Logical array: M[n%3] represents Mnm1, Mn, Mnp1 cyclically with stride 1 but reused in strided update order
    int i;
    M[0] = Mnm1; // M[0] = M_{n-1}
    M[1] = Mn;   // M[1] = M_n
    for (i = 1; i < a; i++) {
        M[(i+1)%3] = ((b - i) * M[(i-1)%3] + (2 * i - b + x) * M[i%3]) / i;
        M[(i-1)%3] = M[i%3]; // Shift: old Mnm1 becomes new Mn in next step
        M[i%3] = M[(i+1)%3];
    }
    // Update output variables
    Mnm1 = M[(a-2)%3];
    Mn = M[(a-1)%3];
    Mnp1 = M[a%3];
}
