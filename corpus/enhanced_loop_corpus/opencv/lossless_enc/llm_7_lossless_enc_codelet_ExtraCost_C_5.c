#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int length;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev = 0, curr = 1;
    for (i = 2; i < length / 2 - 1; ++i) {
        int next = prev + curr;  // Introduce loop-carried flow (RAW) dependency
        prev = curr;
        curr = next;
    }
    // Simulates a Fibonacci-like sequence with strong loop-carried data dependency
}
