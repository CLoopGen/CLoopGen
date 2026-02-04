#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int k;
extern int xbit[31];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every second element in reverse order, then fill gaps)
    // Simulate a strided write pattern with stride 2 in descending index order
    int idx;
    for (k = 30; k >= 0; k -= 2) {
        idx = k;
        xbit[idx] = i % 2;
        i /= 2;
    }
    for (k = 29; k >= 0; k -= 2) {
        idx = k;
        xbit[idx] = i % 2;
        i /= 2;
    }
}
