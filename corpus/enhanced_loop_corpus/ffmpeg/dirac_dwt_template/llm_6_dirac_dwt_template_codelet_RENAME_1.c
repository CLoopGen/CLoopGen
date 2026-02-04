#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern  int w2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (x = 0; x < w2; x++) {
        temp += x;
    }
    // Introduce a write-after-write (WAW) dependency on temp, but no loop-carried dependency on x
    // RAW dependency between x and temp within the loop
    temp = temp * 2;
}
