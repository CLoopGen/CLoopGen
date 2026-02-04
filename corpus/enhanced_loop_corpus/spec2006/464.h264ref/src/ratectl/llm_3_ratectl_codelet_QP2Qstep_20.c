#include <stdio.h>

#include <inttypes.h>

extern int QP;
extern int i;
extern double Qstep;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Memory Access Pattern Modification using consecutive access in reverse order
    // Simulate consecutive memory writes in reverse to alter access pattern
    double temp_arr[32];
    int n = QP / 6;

    // Precompute powers of 2 in reverse order with consecutive memory access
    temp_arr[n - 1] = 2.0;  // Smallest step first in storage

    for (i = n - 2; i >= 0; i--) {
        temp_arr[i] = temp_arr[i + 1] * 2;  // Consecutive backward fill
    }

    // Accumulate final Qstep by applying all factors consecutively from base
    Qstep *= temp_arr[0];
}
