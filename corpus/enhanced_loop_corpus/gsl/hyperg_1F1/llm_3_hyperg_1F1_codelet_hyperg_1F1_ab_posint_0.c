#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int a;
extern  int b;
extern  double x;
extern double Mnp1;
extern double Mn;
extern double Mnm1;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive array-based access pattern
    // Reformulate recurrence using a fixed-size array accessed consecutively with index rotation
    // Simulates cache-friendly sequential access in a sliding window fashion
    double M_buffer[3];  // Circular buffer to hold M[n-1], M[n], M[n+1]
    
    // Initialize buffer with initial values, stored in consecutive locations
    M_buffer[0] = Mnm1;
    M_buffer[1] = Mn;
    M_buffer[2] = Mnp1;

    int idx_nm1 = 0;
    int idx_n   = 1;
    int idx_np1 = 2;

    for (n = a; n > 0; n--) {
        // Compute new value using current window, accessing consecutive conceptual layout
        M_buffer[idx_nm1] = (n * M_buffer[idx_np1] - (2 * n - b + x) * M_buffer[idx_n]) / (b - n);
        
        // Rotate indices to shift window: now new Mnm1 becomes Mn, etc.
        int temp = idx_nm1;
        idx_nm1 = idx_n;
        idx_n = idx_np1;
        idx_np1 = temp;
    }

    // Update original scalar outputs based on final state
    Mn = M_buffer[idx_n];
    Mnp1 = M_buffer[idx_np1];
    Mnm1 = M_buffer[idx_nm1];
}
