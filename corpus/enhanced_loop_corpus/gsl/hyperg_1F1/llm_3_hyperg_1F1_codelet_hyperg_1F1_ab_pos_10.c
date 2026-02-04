#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double a;
extern  double b;
extern  double x;
extern double a0;
extern double Mnm1;
extern double Mn;
extern double Mnp1;
extern double n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Memory Access Pattern Modification - Consecutive array-based sliding window
    // Use a circular buffer with consecutive access pattern to store recurrence values
    double buffer[3]; // Circular buffer to hold three consecutive M values
    int i = 0; // Index for current M, next will be (i+1)%3, previous (i+2)%3 (mod 3)

    // Initialize buffer with initial values: buffer[(i-1)%3] = Mnm1, buffer[i] = Mn
    buffer[(i + 2) % 3] = Mnm1;
    buffer[i] = Mn;

    for (n = a0 + 1.; n < a - 0.10000000000000001; n += 1.) {
        int prev_idx = (i + 2) % 3;   // M[n-1]
        int curr_idx = i;             // M[n]
        int next_idx = (i + 1) % 3;   // M[n+1]

        buffer[next_idx] = ((b - n) * buffer[prev_idx] + (2 * n - b + x) * buffer[curr_idx]) / n;

        // Slide the window: move to next position in circular buffer
        i = next_idx;
    }

    // Final assignment to external variables based on final state
    Mnp1 = buffer[(i + 1) % 3];
    Mn = buffer[i];
    Mnm1 = buffer[(i + 2) % 3];
}
