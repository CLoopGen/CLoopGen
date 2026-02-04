#include <stdio.h>

extern  double R23;
extern  double T23;
extern int i;



void loop(){
    // Variant 1: Consecutive memory-like access pattern using array indexing
    // Simulate consecutive memory accesses by unrolling the loop into a fixed-size array operation
    double R[23];
    double T[23];
    
    R[0] = 0.5 * R23;
    T[0] = 2.0 * T23;
    
    for (i = 1; i < 23; i++) {
        R[i] = 0.5 * R[i-1];
        T[i] = 2.0 * T[i-1];
    }
    
    R23 = R[22];
    T23 = T[22];
}
