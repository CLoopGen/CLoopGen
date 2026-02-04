#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int width;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (i = 0; i < width; ++i) {
        temp += i;
    }
    // Introduces a WAW dependency on 'temp' and a loop-carried RAW dependency via temp's accumulation.
    // The final value of temp depends on all previous iterations, creating a sequential data dependency.
}
