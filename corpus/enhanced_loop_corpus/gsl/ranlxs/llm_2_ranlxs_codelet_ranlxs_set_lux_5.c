#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int k;
extern int xbit[31];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every second element in reverse, then fill gaps)
    // Simulate strided write pattern with forward and backward passes, stride = 2
    int temp[31];
    for (k = 0; k < 31; ++k) {
        temp[k] = i % 2;
        i /= 2;
    }
    // Write to xbit with stride 2 starting from index 0
    for (k = 0; k < 31; k += 2) {
        xbit[k] = temp[k];
    }
    // Fill remaining indices with stride 2 starting from index 1
    for (k = 1; k < 31; k += 2) {
        xbit[k] = temp[k];
    }
}
