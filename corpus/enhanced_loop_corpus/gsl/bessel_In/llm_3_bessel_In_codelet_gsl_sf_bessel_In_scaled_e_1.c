#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int n;
extern  double ax;
extern  int nhi;
extern double Ikp1;
extern double Ik;
extern double Ikm1;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive memory access via rolling window buffer (array of size 3 for reuse)
    // Simulate pipeline using a small circular buffer accessed consecutively
    double I_buffer[3]; // Rolling buffer: 0=Ikm1, 1=Ik, 2=Ikp1
    int prev = 0, curr = 1, next = 2;

    // Initialize buffer with current values
    I_buffer[prev] = Ikm1;
    I_buffer[curr] = Ik;
    I_buffer[next] = Ikp1;

    for (int i = nhi; i > n; i--) {
        int k = i;
        // Rotate indices for consecutive access pattern
        int temp = prev;
        prev = curr;
        curr = next;
        next = temp;

        // Perform update with consecutive memory writes
        I_buffer[next] = I_buffer[prev] + 2. * k / ax * I_buffer[curr];

        // Shift values: Ikp1 = Ik; Ik = Ikm1 => modeled by rotation
        // No explicit assignment needed due to index rotation
    }

    // Map back to scalar outputs based on final index positions
    Ikp1 = I_buffer[prev];
    Ik   = I_buffer[curr];
    Ikm1 = I_buffer[next];
}
