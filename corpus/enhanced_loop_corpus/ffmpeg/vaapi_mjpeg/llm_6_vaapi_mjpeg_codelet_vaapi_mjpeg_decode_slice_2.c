#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (i = 0; i < 4; i++) {
        temp += i;
    }
    // Introduces a loop-carried dependency (WAW on temp) and a RAW dependency (temp depends on previous temp)
    // Eliminates any potential independence of accumulations across iterations.
}
