#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (i = 0; i < 4; i++) {
        temp += i * i;
    }
    // Introduces a loop-carried dependency (WAW on temp) and a RAW dependency (i used before update)
    // Eliminates the original independence by making 'temp' dependent across iterations.
}
