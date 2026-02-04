#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern  int n4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (i = 0; i < n4; i++) {
        temp += i;
    }
    // Introduces a loop-carried dependency (WAW on temp) and a RAW dependency (read i before add)
    // Eliminates parallelism in temp update due to cumulative dependency
}
