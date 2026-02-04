#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern  int w2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (x = 1; x < w2; x++) {
        temp += x;
    }
    // Introduce a write-after-write (WAW) dependency on temp, but no loop-carried dependency on x beyond the original.
    // The variable temp is updated each iteration, creating a WAW hazard if multiple iterations were concurrent.
    // However, loop-carried dependency is broken by using x directly instead of temp in update.
}
