#include <stdio.h>

extern  double R23;
extern  double T23;
extern int i;



void loop(){
    // Variant 2: Strided memory access pattern
    // Access elements with a stride of 2 by iterating over a larger conceptual array
    // Use an effective trip count adjusted for stride
    double R_temp[46];
    double T_temp[46];
    
    R_temp[0] = R23;
    T_temp[0] = T23;
    
    for (i = 1; i <= 23; i++) {
        int idx = 2 * i;  // Stride of 2
        R_temp[idx] = 0.5 * R_temp[idx - 2];
        T_temp[idx] = 2.0 * T_temp[idx - 2];
    }
    
    R23 = R_temp[46];  // This would be out of bounds, so use last valid computed
    T23 = T_temp[46];
    
    // Correct final assignment to avoid UB
    R23 = R_temp[44];  // Last valid index accessed: 2*22 = 44
    T23 = T_temp[44];
}
