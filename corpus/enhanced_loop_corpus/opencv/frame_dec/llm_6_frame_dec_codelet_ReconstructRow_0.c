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
    // Introduces a loop-carried RAW dependency: each iteration depends on the previous value of temp
    // Eliminates any WAW or WAR hazards by using only one accumulator
}
