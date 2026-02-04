#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (i = 0; i <= 2; ++i) {
        temp += i;
    }
    // Introduces a WAW dependency on 'temp' across iterations (loop-carried dependence)
    // Also introduces RAW: each iteration reads 'temp' written in previous iteration
}
