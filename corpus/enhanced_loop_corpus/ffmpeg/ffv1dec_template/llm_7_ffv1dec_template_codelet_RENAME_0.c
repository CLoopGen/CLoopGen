#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    int values[4];
    for (i = 0; i < 4; i++) {
        values[i] = i * i;
        x = values[i]; // WAW dependency on x, but no loop-carried dependency
    }
}
