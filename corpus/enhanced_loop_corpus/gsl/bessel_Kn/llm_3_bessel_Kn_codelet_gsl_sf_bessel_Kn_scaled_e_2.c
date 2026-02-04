#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int n;
extern double two_over_x;
extern double b_jm1;
extern double b_j;
extern double b_jp1;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive array traversal with sliding window
    // Representing recurrence using a circular buffer of size 3 for consecutive accesses
    double buf[3]; // Circular buffer: indices 0,1,2 represent b_{j-1}, b_j, b_{j+1}
    buf[0] = b_jm1;
    buf[1] = b_j;
    for (j = 1; j < n; j++) {
        int prev_idx = (j - 1) % 3;
        int curr_idx = j % 3;
        int next_idx = (j + 1) % 3;
        buf[next_idx] = buf[prev_idx] + j * two_over_x * buf[curr_idx];
        // Slide window: no explicit assignment needed due to modulo indexing
    }
    // Recover final values from buffer
    b_jm1 = buf[(n - 1) % 3];
    b_j = buf[n % 3];
}
