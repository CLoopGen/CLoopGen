#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int numcomps;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (i = 0; i < numcomps; i++) {
        temp += i;
    }
    // Introduces a WAW dependency on 'temp' and a loop-carried dependency via accumulation.
    // Original loop had no dependencies; now there's a flow (RAW) dependency where each iteration reads 
    // the value written in the previous iteration. No external side effects, but internal state accumulates.
}
