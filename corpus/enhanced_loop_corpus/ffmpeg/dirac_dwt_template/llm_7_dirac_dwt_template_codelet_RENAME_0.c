#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern  int w2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev = 0;
    for (x = 1; x < w2; x++) {
        int next = prev + x;
        prev = next;
    }
    // Introduce a loop-carried read-after-write (RAW) dependency via 'prev'.
    // Each iteration depends on the previous iteration's result, making this loop serial and carrying strong data dependency.
    // This transforms the loop from independent iterations to one with sequential data flow.
}
