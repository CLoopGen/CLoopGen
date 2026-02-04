#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (i = 0; i < width; ++i) {
        temp += i;
    }
    // Introduces a loop-carried dependency (WAW on temp) and a RAW dependency (read i, write temp)
    // Eliminates any previous independence by making each iteration dependent on the accumulated value
}
