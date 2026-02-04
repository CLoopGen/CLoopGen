#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (i = 0; i < h; i++) {
        temp += i;
    }
    // Introduce a write-after-write (WAW) dependency on temp, but no loop-carried dependency beyond accumulation.
    // RAW dependency: each iteration reads 'i' and 'temp' written in previous iteration.
    // Loop-carried dependency via 'temp' creates a sequential data dependency across iterations.
}
