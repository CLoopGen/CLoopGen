#include <stdio.h>

double sum[5];
int m;

void init_vars() {
    // Initialize sum array to zero as per loop logic
    for (int i = 0; i < 5; i++) {
        sum[i] = 0.0;
    }
    m = 0; // Initial value for loop control
}