#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int w2;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_val;
    for (x = 0; x < w2; x++) {
        local_val = x * 2;
        if (local_val > 10) {
            x++; // Modify loop index, creating a WAR-like scenario (write after read of x)
        }
        // Eliminate potential loop-carried dependencies by making local_val redefined each iteration.
        // The increment of x inside the loop introduces a loop-carried control and anti-dependency.
        // No data is carried across iterations except through loop variable mutation.
    }
}
