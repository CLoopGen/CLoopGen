#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (i = 0; i < 3; i++) {
        temp += i;
    }
    // Introduces a WAW dependency on `temp` and a loop-carried RAW dependency via `temp += i`
    // Each iteration depends on the previous value of `temp`, creating a sequential data dependency chain
}
