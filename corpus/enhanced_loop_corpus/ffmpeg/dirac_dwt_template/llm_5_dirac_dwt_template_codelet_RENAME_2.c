#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int w2;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_x;
    for (x = 0; x < w2; x++) {
        local_x = x + 1;
        x = local_x; // WAR hazard introduced: write after read of 'x'; also creates loop-carried dependency
        if (x >= w2) break;
    }
    // This variant modifies the loop index within the body, creating a loop-carried dependency
    // and introducing a write-after-read (WAR) pattern through direct assignment to 'x'
}
