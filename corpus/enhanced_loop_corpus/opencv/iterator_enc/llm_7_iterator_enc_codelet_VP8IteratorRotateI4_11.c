#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_val[4];
    for (i = 0; i <= 3; ++i) {
        local_val[i] = i + 1;
    }
    i = local_val[3];
    // Eliminates loop-carried dependency by making each iteration independent
    // Each write to local_val[i] is independent (no RAW, WAR, WAW between iterations)
    // Final assignment to 'i' breaks any potential dependency chain from the loop index
}
