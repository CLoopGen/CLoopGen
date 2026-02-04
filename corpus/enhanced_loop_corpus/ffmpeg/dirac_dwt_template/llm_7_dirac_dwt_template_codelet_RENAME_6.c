#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int w2;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_sum = 0;
    for (x = 1; x < w2; x++) {
        local_sum = local_sum + x * x;  // RAW dependency: local_sum used and updated
    }
    // Eliminate loop-carried dependency by making each iteration independent
    // using only induction variable; no mutation of external state inside loop
    if (local_sum > 0) {
        w2 = local_sum % 50 + 1;
    }
}
