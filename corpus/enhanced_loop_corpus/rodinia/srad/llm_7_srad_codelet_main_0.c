#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int Nr;
extern int *iN;
extern int *iS;
extern long i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < Nr; i++) {
        int temp_val = i + 1;
        iS[i] = temp_val;     // Write to iS
        iN[i] = temp_val - 2; // Use same computed value, but no direct loop-carried dependency
    }
    // Eliminated WAW and WAR hazards by ensuring single writes per index and no overlapping write-use across iterations
}
