#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int w2;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (x = 0; x < w2; x++) {
        temp += x;
    }
    // Introduce a write-after-write (WAW) dependency on temp, but no loop-carried dependency beyond accumulation.
    // RAW dependency: temp is read after being written in previous iteration.
    // This creates a loop-carried flow dependency on 'temp'.
}
