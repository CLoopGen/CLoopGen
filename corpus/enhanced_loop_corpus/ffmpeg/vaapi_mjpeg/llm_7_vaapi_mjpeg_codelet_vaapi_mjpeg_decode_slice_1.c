#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp[2];
    for (i = 0; i < 2; i++) {
        temp[i] = i * i;
    }
    // Eliminates loop-carried dependencies by using distinct memory locations
    // Each iteration writes to a separate array element (no WAW or WAR hazards across iterations)
    // Independent iterations with no loop-carried data dependence
}
