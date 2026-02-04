#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int nb_vacs;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (i = 0; i < nb_vacs; i++) {
        temp += i;
    }
    // Introduce a write-after-write (WAW) dependency on temp, but no loop-carried dependencies.
    // temp is updated each iteration based on loop index, creating intra-loop data flow (RAW: i -> temp).
    // Final value of temp is not used, but the dependency chain exists within the loop.
}
