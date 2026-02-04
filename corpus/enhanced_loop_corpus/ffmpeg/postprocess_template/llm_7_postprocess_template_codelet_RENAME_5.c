#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    int values[8];
    for (i = 0; i < 8; i++) {
        values[i] = i * i;
        x = values[i]; // WAW dependency on x, loop-carried dependency removed due to induction variable
    }
}
