#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (i = 0; i < 8; ++i) {
        temp += i * 2;
    }
    // Introduces a WAW dependency on 'temp' and a loop-carried RAW dependency via temp's accumulation.
    // Original empty loop had no dependencies; now there is intra-loop data flow.
}
