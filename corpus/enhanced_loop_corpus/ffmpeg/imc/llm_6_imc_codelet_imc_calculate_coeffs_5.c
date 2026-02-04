#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float workT2[32];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp = 0.0;
    for (i = 0; i < 32; i++) {
        temp += workT2[i];  // Introduce RAW dependency: each iteration reads workT2[i] and accumulates into temp
        workT2[i] = 0.0;   // Write after read in same iteration, but no loop-carried WAW or WAR due to independent writes
    }
    // Additional use of temp to prevent dead code elimination
    if (temp > 1e30) {
        workT2[0] = temp;
    }
}
