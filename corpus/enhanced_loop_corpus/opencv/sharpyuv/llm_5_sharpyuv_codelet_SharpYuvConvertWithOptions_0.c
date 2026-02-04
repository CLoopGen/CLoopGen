#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp[3];
    for (i = 0; i < 3; ++i) {
        temp[i] = i * 2;
    }
    // Eliminates loop-carried dependencies by writing to distinct memory locations.
    // Each iteration writes to a unique array element, removing WAW and WAR hazards across iterations.
    // Results in fully parallelizable loop with no data dependency between iterations.
}
