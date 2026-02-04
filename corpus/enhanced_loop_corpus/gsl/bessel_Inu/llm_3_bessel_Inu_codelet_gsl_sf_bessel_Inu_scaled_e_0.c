#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double x;
extern int N;
extern double mu;
extern double K_nu;
extern double K_nup1;
extern double K_num1;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive array traversal simulating pipeline with local history buffer
    // Use a circular buffer of size 3 to store recent K values accessed consecutively
    double K_buf[3];
    int idx_prev1 = 0, idx_curr = 1, idx_next = 2;

    // Initialize buffer with initial conditions
    K_buf[idx_prev1] = K_num1;
    K_buf[idx_curr]  = K_nu;
    K_buf[idx_next]  = K_nup1;

    for (n = 0; n < N; n++) {
        // Rotate indices to simulate sliding window (consecutive logical access)
        int temp = idx_prev1;
        idx_prev1 = idx_curr;
        idx_curr = idx_next;
        idx_next = temp;

        // Update next value using current and previous
        K_buf[idx_next] = 2. * (mu + n + 1) / x * K_buf[idx_curr] + K_buf[idx_prev1];
    }

    // Recover final scalar states from buffer
    K_num1 = K_buf[idx_prev1];
    K_nu   = K_buf[idx_curr];
    K_nup1 = K_buf[idx_next];
}
