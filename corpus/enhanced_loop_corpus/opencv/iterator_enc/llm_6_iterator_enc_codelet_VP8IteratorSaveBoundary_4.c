#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (i = 0; i < 8; ++i) {
        temp += i * 2;
    }
    // Introduces a loop-carried dependency (WAW on temp) and a RAW dependency (read i before use)
    // Each iteration depends on the previous value of temp, creating a sequential data dependency.
}
