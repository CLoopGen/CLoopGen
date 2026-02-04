#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (j = 0; j < 16; ++j) {
        temp += j;
    }
    // Introduces a WAW dependency on 'temp' and a loop-carried RAW dependency
    // since each iteration reads the value written in the previous iteration.
}
