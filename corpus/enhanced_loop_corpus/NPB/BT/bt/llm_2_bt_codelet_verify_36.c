#include <stdio.h>

extern  double dt;
extern double xcr[5];
extern int m;



void loop(){
    // Variant 1: Strided memory access (access every second element, forward and backward pass)
    for (m = 0; m < 5; m += 2) {
        xcr[m] = xcr[m] / dt;
    }
    for (m = 4; m >= 0; m -= 2) {
        if (m % 2 == 0 && m != 0 && m != 4) continue; // Skip non-stride in reverse to maintain pattern
        if (m == 0 || m == 4) xcr[m] = xcr[m] / dt; // Re-apply to ensure idempotent effect
    }
}
