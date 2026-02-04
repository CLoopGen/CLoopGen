#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (i = 0; i < h; i++) {
        temp += i;
    }
    // Introduces a loop-carried dependency (WAW on temp) and a RAW dependency (i used before update)
    // Eliminates the empty loop but maintains valid control flow with data accumulation
}
