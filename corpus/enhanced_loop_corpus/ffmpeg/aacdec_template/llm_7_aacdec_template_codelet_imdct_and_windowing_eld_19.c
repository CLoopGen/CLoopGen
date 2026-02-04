#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern  int n4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_data[4];
    for (i = 0; i < n4; i++) {
        local_data[i & 3] = i * 2;
        // Removes loop-carried dependencies by using modulo indexing
        // Each iteration writes independently to one of four slots, breaking WAW and WAR hazards across iterations
        // Enables potential pipelining or unrolling optimizations
    }
}
