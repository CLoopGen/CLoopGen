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
    // Introduce a write-after-read (WAR) and read-after-write (RAW) dependency on temp
    // Also creates a loop-carried dependency via temp accumulation
}
